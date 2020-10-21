/*
 *  MapboxVectorStyleBackground.mm
 *  WhirlyGlobe-MaplyComponent
 *
 *  Created by Steve Gifford on 2/17/15.
 *  Copyright 2011-2015 mousebird consulting
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#import "MapboxVectorStyleBackground.h"
#import "WhirlyKitLog.h"
#import "Tesselator.h"

namespace WhirlyKit
{

bool MapboxVectorBackgroundPaint::parse(PlatformThreadInfo *inst,
                                        MapboxVectorStyleSetImpl *styleSet,
                                        DictionaryRef styleEntry)
{
    color = styleSet->transColor("background-color",styleEntry,RGBAColor::black());
    styleSet->unsupportedCheck("background-image","paint_background",styleEntry);

    opacity = styleSet->transDouble("background-opacity",styleEntry,1.0);
    
    return true;
}

bool MapboxVectorLayerBackground::parse(PlatformThreadInfo *inst,
                                        DictionaryRef styleEntry,
                                        MapboxVectorStyleLayerRef refLayer,
                                        int drawPriority)
{
    if (!MapboxVectorStyleLayer::parse(inst,styleEntry,refLayer,drawPriority)) {
        return false;
    }
    
//    styleSet->unsupportedCheck("layout","background",styleEntry);
    
    if (!paint.parse(inst,styleSet,styleEntry->getDict("paint"))) {
        return false;
    }
    
    // Mess directly with the opacity because we're using it for other purposes
    if (styleEntry->hasField("alphaoverride")) {
        paint.color->setAlphaOverride(styleEntry->getDouble("alphaoverride"));
    }
    
    return true;
}

void MapboxVectorLayerBackground::buildObjects(PlatformThreadInfo *inst,
                                               std::vector<VectorObjectRef> &vecObjs,
                                               VectorTileDataRef tileInfo)
{
    ComponentObjectRef compObj = styleSet->makeComponentObject(inst);

    const auto color = styleSet->backgroundColor(inst, tileInfo->ident.level);

    std::vector<VectorRing> loops { VectorRing() };
    tileInfo->geoBBox.asPoints(loops.back());
    
    VectorTrianglesRef trisRef = VectorTriangles::createTriangles();
    TesselateLoops(loops, trisRef);
    //trisRef->setAttrDict(ar->getAttrDict());
    trisRef->initGeoMbr();
    ShapeSet tessShapes { trisRef };
                
    VectorInfo vecInfo;
    vecInfo.hasExp = true;
    vecInfo.filled = true;
    vecInfo.centered = true;
    vecInfo.color = *color;
    vecInfo.zoomSlot = styleSet->zoomSlot;
    vecInfo.zBufferWrite = styleSet->tileStyleSettings->zBufferWrite;
    vecInfo.zBufferRead = styleSet->tileStyleSettings->zBufferRead;
    vecInfo.colorExp = paint.color->expression();
    vecInfo.opacityExp = paint.opacity->expression();
    vecInfo.programID = styleSet->vectorArealProgramID;
    vecInfo.drawPriority = drawPriority + tileInfo->ident.level * std::max(0, styleSet->tileStyleSettings->drawPriorityPerLevel);
    vecInfo.drawOrder = tileInfo->tileNumber();

    if (minzoom != 0 || maxzoom < 1000) {
        vecInfo.minZoomVis = minzoom;
        vecInfo.maxZoomVis = maxzoom;
    }

    const SimpleIdentity vecID = styleSet->vecManage->addVectors(&tessShapes, vecInfo, tileInfo->changes);
    if (vecID != EmptyIdentity) {
        compObj->vectorIDs.insert(vecID);
        
        if (selectable)
            compObj->vecObjs = vecObjs;
    }
    
    if (!compObj->vectorIDs.empty()) {
        styleSet->compManage->addComponentObject(compObj);
        tileInfo->compObjs.push_back(compObj);
    }
}

}
