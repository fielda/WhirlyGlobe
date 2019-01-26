/*
 *  ShapeDrawableBuilder.h
 *  WhirlyGlobeLib
 *
 *  Created by Steve Gifford on 9/28/11.
 *  Copyright 2011-2016 mousebird consulting. All rights reserved.
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

#import "Identifiable.h"
#import "WhirlyVector.h"
#import "BaseInfo.h"
#import "BasicDrawable.h"


namespace WhirlyKit
{

/// Used to pass shape info between the shape layer and the drawable builder
///  and within the threads of the shape layer
class ShapeInfo : public BaseInfo
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    
    ShapeInfo();
    ~ShapeInfo();

    void setColor(RGBAColor value) { color = value; }
    RGBAColor getColor() { return color; }

    void setLineWidth(float value) { lineWidth = value; }
    float getLineWidth() { return lineWidth; }

    void setShapeId(WhirlyKit::SimpleIdentity value) { shapeId = value; }
    WhirlyKit::SimpleIdentity getShapeId() { return shapeId; }

    void setInsideOut(bool value) { insideOut = value; }
    bool getInsideOut() { return insideOut; }

    void setZBufferRead(bool value) { zBufferRead = value; }
    bool getZBufferRead() { return zBufferRead; }

    void setZBufferWrite(bool value) { zBufferWrite = value; }
    bool getZBufferWrite() { return zBufferWrite; }

    void setHasCenter(bool value) { hasCenter = value; }
    bool getHasCenter() { return hasCenter; }

    void setCenter(Point3d value) { center = value; }
    Point3d getCenter() { return center; }
    
    void setRenderTarget(SimpleIdentity targetID) { renderTargetID = targetID; }

public:
    RGBAColor color;
    float lineWidth;
    SimpleIdentity shapeId;
    bool insideOut;
    bool zBufferRead;
    bool zBufferWrite;
    bool hasCenter;
    WhirlyKit::Point3d center;
    SimpleIdentity renderTargetID;
};



/** This drawable builder is associated with the shape layer.  It's
    exposed so it can be used by the active model version as well.
  */
class ShapeDrawableBuilder
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    
    /// Construct the builder with the fade value for each created drawable and
    ///  whether we're doing lines or points
    ShapeDrawableBuilder(WhirlyKit::CoordSystemDisplayAdapter *coordAdapter,ShapeInfo *shapeInfo,bool linesOrPoints,const Point3d &center);
    virtual ~ShapeDrawableBuilder();

    /// A group of points (in display space) all at once
    void addPoints(Point3fVector &pts,RGBAColor color,Mbr mbr,float lineWidth,bool closed);

    /// Flush out the current drawable (if there is one) to the list of finished ones
    void flush();

    /// Retrieve the scene changes and the list of drawable IDs for later
    void getChanges(WhirlyKit::ChangeSet &changeRequests,SimpleIDSet &drawIDs);

    ShapeInfo *getShapeInfo() { return shapeInfo; }

public:
    CoordSystemDisplayAdapter *coordAdapter;
    GLenum primType;
    ShapeInfo *shapeInfo;
    Mbr drawMbr;
    BasicDrawable *drawable;
    std::vector<BasicDrawable *> drawables;
    Point3d center;
};

/** Drawable Builder (Triangle version) is used to build up shapes made out of triangles.
    It's intended for use by the shape layer and the active version of that.
 */
class ShapeDrawableBuilderTri
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    
    /// Construct with the visual description
    ShapeDrawableBuilderTri(WhirlyKit::CoordSystemDisplayAdapter *coordAdapter,ShapeInfo *shapeInfo,const Point3d &center);
    virtual ~ShapeDrawableBuilderTri();

    // If set the geometry is already in OpenGL clip coordinates, so we don't transform it
    void setClipCoords(bool newClipCoords);
    
    // If set, we'll apply the given texture
    void setTexIDs(const std::vector<SimpleIdentity> &texIDs);

    // Add a triangle with normals
    void addTriangle(Point3f p0,Point3f n0,RGBAColor c0,Point3f p1,Point3f n1,RGBAColor c1,Point3f p2,Point3f n2,RGBAColor c2,Mbr shapeMbr);

    // Add a triangle with normals
    void addTriangle(Point3d p0,Point3d n0,RGBAColor c0,Point3d p1,Point3d n1,RGBAColor c1,Point3d p2,Point3d n2,RGBAColor c2,Mbr shapeMbr);

    // Add a triangle with normals and texture coords
    void addTriangle(const Point3d &p0,const Point3d &n0,RGBAColor c0,const TexCoord &tx0,const Point3d &p1,const Point3d &n1,RGBAColor c1,const TexCoord &tx1,const Point3d &p2,const Point3d &n2,RGBAColor c2,const TexCoord &tx2,Mbr shapeMbr);
    
    // Add a group of pre-build triangles
    void addTriangles(Point3fVector &pts,Point3fVector &norms,std::vector<RGBAColor> &colors,std::vector<BasicDrawable::Triangle> &tris);

    // Add a convex outline, triangulated
    void addConvexOutline(Point3fVector &pts,Point3f norm,RGBAColor color,Mbr shapeMbr);

    // Add a convex outline, triangulated
    void addConvexOutline(Point3dVector &pts,Point3d norm,RGBAColor color,Mbr shapeMbr);

    // Add a convex outline, triangulated with texture coords
    void addConvexOutline(Point3dVector &pts,std::vector<TexCoord> &texCoords,Point3d norm,RGBAColor color,Mbr shapeMbr);

    // Add a complex outline, triangulated
    void addComplexOutline(Point3dVector &pts,Point3d norm,RGBAColor color,Mbr shapeMbr);

    /// Flush out the current drawable (if there is one) to the list of finished ones
    void flush();

    /// Retrieve the scene changes and the list of drawable IDs for later
    void getChanges(ChangeSet &changeRequests,SimpleIDSet &drawIDs);

    ShapeInfo *getShapeInfo() { return shapeInfo; }

public:
    // Creates a new local drawable with all the appropriate settings
    void setupNewDrawable();

    CoordSystemDisplayAdapter *coordAdapter;    
    Mbr drawMbr;
    ShapeInfo *shapeInfo;
    BasicDrawable *drawable;
    std::vector<BasicDrawable *> drawables;
    std::vector<SimpleIdentity> texIDs;
    Point3d center;
    bool clipCoords;
};

}
