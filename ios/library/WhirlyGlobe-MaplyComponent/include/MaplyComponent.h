/*
 *  MaplyComponent.h
 *  MaplyComponent
 *
 *  Created by Steve Gifford on 9/6/12.
 *  Copyright 2012-2017 mousebird consulting
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

#import "MaplyCoordinate.h"
#import "MaplyCoordinateSystem.h"
#import "MaplyMatrix.h"
#import "MaplyVertexAttribute.h"
#import "MaplyTexture.h"
#import "MaplyRenderTarget.h"
#import "MaplyVariableTarget.h"
#import "MaplyLabel.h"
#import "MaplyScreenLabel.h"
#import "MaplyMarker.h"
#import "MaplyScreenMarker.h"
#import "MaplyShape.h"
#import "MaplySticker.h"
#import "MaplyBillboard.h"
#import "MaplyParticleSystem.h"
#import "MaplyVectorObject.h"
#import "MaplyViewTracker.h"
#import "MaplyViewController.h"
#import "MaplyQuadSampler.h"
#import "MaplyRemoteTileFetcher.h"
#import "MaplyMBTileFetcher.h"
#import "MaplyUpdateLayer.h"
#import "MaplyQuadImageLoader.h"
#import "MaplyQuadImageFrameLoader.h"
#import "MaplyTileSource.h"
#import "MaplyElevationSource.h"
#import "MaplyElevationDatabase.h"
#import "MaplyIconManager.h"
#import "MaplyTextureBuilder.h"
#import "MaplyGeomModel.h"
#import "MaplyVertexAttribute.h"
#import "MaplyStarsModel.h"
#import "MaplySun.h"
#import "MaplyAtmosphere.h"
#import "MaplyMoon.h"
#import "MaplyPoints.h"
#import "MaplyGeomBuilder.h"
#import "MaplyColorRampGenerator.h"
#import "MaplyAerisTiles.h"

#import "MapboxVectorTiles.h"
#import "MapboxVectorTilesPagingDelegate.h"
#import "MapboxVectorImageInterpreter.h"
#import "MapnikStyleSet.h"
#import "MapboxMultiSourceTileInfo.h"
#import "MaplyVectorStyleSimple.h"
#import "SLDStyleSet.h"
#import "MapboxVectorStyleSet.h"
#import "MapboxVectorStyleFill.h"
#import "MapboxVectorStyleBackground.h"
#import "MapboxVectorStyleLine.h"
#import "MapboxVectorStyleRaster.h"
#import "MapboxVectorStyleSymbol.h"
