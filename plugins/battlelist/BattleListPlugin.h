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

#ifndef BATTLELISTPLUGIN_H
#define BATTLELISTPLUGIN_H

#include <QtPlugin>
#include <QObject>
#include <QVariantMap>

#include <HookInterface.h>
#include <PluginInterface.h>

#include "BattleList.h"
#include "BattleListPluginInterface.h"

class BattleListPlugin: public QObject, public PluginInterface, public BattleListPluginInterface {
	Q_OBJECT
    Q_INTERFACES(PluginInterface BattleListPluginInterface)

public:
    void install(HookInterface*, SettingsInterface*) throw(std::exception);
	void uninstall();

    const BattleList* entries() const;
    const BattleListEntry* findById(const quint32 id) const;
    const BattleListEntry* findByName(const QString& name) const;

private:
    BattleList* list_;
};

#endif
