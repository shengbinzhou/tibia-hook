/* Copyright (c) 2012 Gillis Van Ginderachter <supergillis@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MINIMAPUIPLUGIN_H
#define MINIMAPUIPLUGIN_H

#include "MiniMapView.h"

#include <HookInterface.h>
#include <PathFinderPluginInterface.h>
#include <PluginInterface.h>
#include <PositionTrackerPluginInterface.h>
#include <WalkerPluginInterface.h>

#include <QObject>
#include <QtPlugin>

class MiniMapUIPlugin: public QObject, public PluginInterface {
	Q_OBJECT
    Q_INTERFACES(PluginInterface)

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    Q_PLUGIN_METADATA(IID "be.gillis.minimapui" FILE "meta.js")
#endif

public:
    MiniMapUIPlugin();

    void install(HookInterface*, SettingsInterface*) throw(std::exception);
    void uninstall();

protected:
    MiniMapPluginInterface* minimap_;
    PathFinderPluginInterface* finder_;
    PositionTrackerPluginInterface* tracker_;
    WalkerPluginInterface* walker_;

    friend class MiniMapView;

private:
    HookInterface* hook_;
    MiniMapView* view_;
};

#endif
