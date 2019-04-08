/*
 *  QuadImageFrameLoader_jni.cpp
 *  WhirlyGlobeLib
 *
 *  Created by Steve Gifford on 4/8/19.
 *  Copyright 2011-2019 mousebird consulting
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

#import "QuadLoading_jni.h"
#import "Geometry_jni.h"
#import "Scene_jni.h"
#import "Renderer_jni.h"
#import "com_mousebird_maply_QuadImageFrameLoader.h"

using namespace WhirlyKit;

JNIEXPORT void JNICALL Java_com_mousebird_maply_QuadImageFrameLoader_setCurrentImageNative
        (JNIEnv *env, jobject obj, jdouble curImage)
{
    try {
        QuadImageFrameLoader_AndroidRef *loader = QuadImageFrameLoaderClassInfo::getClassInfo()->getObject(env,obj);
        if (!loader)
            return;

        (*loader)->setCurFrame(curImage);
    }
    catch (...)
    {
        __android_log_print(ANDROID_LOG_VERBOSE, "Maply", "Crash in QuadImageFrameLoader::setCurrentImage()");
    }
}
