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

#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QString>

#include <HookInterface.h>

class PluginInterface {
public:
	virtual ~PluginInterface() {}

	virtual QString name() const = 0;
	virtual int version() const = 0;

    virtual void install(HookInterface*) throw(std::exception) = 0;
	virtual void uninstall() = 0;
};

Q_DECLARE_INTERFACE(PluginInterface, "PluginInterface")

#endif