/*  LightingTestCase.kt
 *  WhirlyGlobeLib
 *
 *  Created by jmnavarro
 *  Copyright 2011-2021 mousebird consulting
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
 */
package com.mousebirdconsulting.autotester.TestCases

import android.app.Activity
import com.mousebird.maply.GlobeController
import com.mousebirdconsulting.autotester.Framework.MaplyTestCase

class LightingTestCase(activity: Activity?) :
        MaplyTestCase(activity, "Lighting Test", TestExecutionImplementation.Globe) {

    private var adapter: LightingAdapter? = null

    @Throws(Exception::class)
    override fun setUpWithGlobe(globeVC: GlobeController): Boolean {
        baseView.setUpWithGlobe(globeVC)
        globeVC.addPostSurfaceRunnable {
            adapter = LightingAdapter(globeVC)
        }
        return true
    }
    
    override fun shutdown() {
        adapter = null
        controller?.clearLights()
        baseView.shutdown()
        super.shutdown()
    }
    
    private val baseView = StamenRemoteTestCase(getActivity()).apply {
        doColorChange = false
    }
}