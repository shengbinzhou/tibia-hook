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

#ifndef WALKERPLUGININTERFACE_H
#define WALKERPLUGININTERFACE_H

#include <Direction.h>

#include <QtPlugin>
#include <QList>

class WalkerPluginInterface {
public:
    virtual void walk(const QList<Direction>& directions) = 0;
    virtual void move(const Direction& direction) = 0;
};

Q_DECLARE_INTERFACE(WalkerPluginInterface, "WalkerPluginInterface")

#endif
