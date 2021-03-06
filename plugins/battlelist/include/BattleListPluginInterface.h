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

#ifndef BATTLELISTPLUGININTERFACE_H
#define BATTLELISTPLUGININTERFACE_H

#include <QtPlugin>

#include <BattleList.h>
#include <BattleListEntryInterface.h>

class BattleListPluginInterface {
public:
    virtual ~BattleListPluginInterface() {}

    virtual QList<BattleListEntryInterface*> entries() const = 0;
    virtual BattleListEntryInterface* findById(const quint32 id) const = 0;
    virtual BattleListEntryInterface* findByName(const QString& name) const = 0;
};

Q_DECLARE_INTERFACE(BattleListPluginInterface, "BattleListPluginInterface")

#endif
