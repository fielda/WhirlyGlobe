/*
 *  Lighting.cpp
 *  WhirlyGlobeLib
 *
 *  Created by jmnavarro
 *  Copyright 2011-2019 mousebird consulting.
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
#import "Lighting.h"
#import "Program.h"
#import "ProgramGLES.h"

using namespace Eigen;

namespace WhirlyKit
{
    
DirectionalLight::DirectionalLight()
{
    viewDependent = true;
    pos = Eigen::Vector3f(0,0,0);
    ambient = Eigen::Vector4f(1,1,1,1);
    diffuse = Eigen::Vector4f(1,1,1,1);
    specular = Eigen::Vector4f(0,0,0,0);
}

DirectionalLight::~DirectionalLight()
{
}

bool DirectionalLight::bindToProgram(Program *program, int index, Eigen::Matrix4f modelMat) const
{
    Eigen::Vector3f dir = pos.normalized();
    Eigen::Vector3f halfPlane = (dir + Eigen::Vector3f(0,0,1)).normalized();

    ProgramGLES *programGLES = dynamic_cast<ProgramGLES *>(program);
    if (programGLES) {
        programGLES->setUniform(lightViewDependNameIDs[index], (viewDependent ? 0.0f : 1.0f));
        programGLES->setUniform(lightDirectionNameIDs[index], dir);
        programGLES->setUniform(lightHalfplaneNameIDs[index], halfPlane);
        programGLES->setUniform(lightAmbientNameIDs[index], ambient);
        programGLES->setUniform(lightDiffuseNameIDs[index], diffuse);
        programGLES->setUniform(lightSpecularNameIDs[index], specular);
    }

    return true;
}


Material::Material() :
    ambient(Eigen::Vector4f(1,1,1,1)),
    diffuse(Eigen::Vector4f(1,1,1,1)),
    specular(Eigen::Vector4f(1,1,1,1)),
    specularExponent(1)
{
}

Material::~Material()
{
}

bool Material::bindToProgram(Program *program)
{
    ProgramGLES *programGLES = dynamic_cast<ProgramGLES *>(program);
    if (programGLES) {
        programGLES->setUniform(materialAmbientNameID, ambient);
        programGLES->setUniform(materialDiffuseNameID, diffuse);
        programGLES->setUniform(materialSpecularNameID, specular);
        programGLES->setUniform(materialSpecularExponentNameID, specularExponent);
    }

    return true;
}

}

