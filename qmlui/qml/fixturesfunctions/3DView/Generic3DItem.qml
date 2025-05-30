/*
  Q Light Controller Plus
  Generic3DItem.qml

  Copyright (c) Massimo Callegari

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

import QtQuick

import Qt3D.Core
import Qt3D.Render
import Qt3D.Extras

import org.qlcplus.classes 1.0
import "."

Entity
{
    id: genericEntity

    property int itemID: -1
    property alias itemSource: eSceneLoader.source
    property bool isSelected: false

    property Layer sceneLayer
    property Effect effect

    SceneLoader
    {
        id: eSceneLoader

        onStatusChanged:
        {
            if (status === SceneLoader.Ready)
                View3D.initializeItem(itemID, genericEntity, eSceneLoader)
        }
    }

    property Transform transform: Transform { }

    components: [ eSceneLoader, transform ]
}
