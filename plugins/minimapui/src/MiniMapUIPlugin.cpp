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

#include "MiniMapUIPlugin.h"

#include <MiniMapPluginInterface.h>

#include <stdexcept>

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
Q_EXPORT_PLUGIN2(be.gillis.minimapui, MiniMapUIPlugin)
#endif

MiniMapUIPlugin::MiniMapUIPlugin():
    model_(NULL),
    view_(NULL) {
}

void MiniMapUIPlugin::install(HookInterface* hook, SettingsInterface* settings) throw(std::exception) {
    QObject* plugin = hook->plugins()->findPluginByName("minimap");
    if(plugin == NULL) {
        throw std::runtime_error("The 'minimap' plugin must be loaded before loading the 'minimapui' plugin!");
    }

    MiniMapPluginInterface* miniMapPlugin = qobject_cast<MiniMapPluginInterface*>(plugin);
    if(miniMapPlugin == NULL) {
        throw std::runtime_error("The 'minimap' plugin could not be loaded!");
    }

    model_ = new MiniMapModel(miniMapPlugin->miniMap());
    view_ = new MiniMapView();
    view_->setModel(model_);

    hook_ = hook;
    hook_->ui()->addTab(view_, "Map");

    hook_->addIncomingReadOnlyProxy(100, model_);
    hook_->addIncomingReadOnlyProxy(101, model_);
    hook_->addIncomingReadOnlyProxy(102, model_);
    hook_->addIncomingReadOnlyProxy(103, model_);
    hook_->addIncomingReadOnlyProxy(104, model_);
    hook_->addIncomingReadOnlyProxy(190, model_);
    hook_->addIncomingReadOnlyProxy(191, model_);
}

void MiniMapUIPlugin::uninstall() {
    // Clean up proxies
    hook_->removeIncomingReadOnlyProxy(191, model_);
    hook_->removeIncomingReadOnlyProxy(190, model_);
    hook_->removeIncomingReadOnlyProxy(104, model_);
    hook_->removeIncomingReadOnlyProxy(103, model_);
    hook_->removeIncomingReadOnlyProxy(102, model_);
    hook_->removeIncomingReadOnlyProxy(101, model_);
    hook_->removeIncomingReadOnlyProxy(100, model_);

    // Clean up UI
    hook_->ui()->removeTab(view_);

    // Clean up objects
    delete view_;
    delete model_;
    view_ = NULL;
    model_ = NULL;
    hook_ = NULL;
}
