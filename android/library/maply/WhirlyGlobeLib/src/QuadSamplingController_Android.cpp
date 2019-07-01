/*
 *  QuadSamplingController_Android.cpp
 *  WhirlyGlobeLib
 *
 *  Created by Steve Gifford on 3/28/19.
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

#import "QuadSamplingController_Android.h"
#import "QuadImageFrameLoader_Android.h"

namespace WhirlyKit
{
QuadSamplingController_Android::QuadSamplingController_Android()
{
}

QuadSamplingController_Android::~QuadSamplingController_Android()
{
}

void QuadSamplingController_Android::setEnv(JNIEnv *env)
{
    auto displayControl = getDisplayControl();
    if (!displayControl)
        return;

    // All the builders will need their ENV updated so they can create valid Java objects
    for (QuadTileBuilderDelegateRef builder : builderDelegates) {
        JNIEnvDependent *envDep = dynamic_cast<JNIEnvDependent *>(builder.get());
        if (envDep) {
            envDep->setEnv(env);
        }
    }
}

}
