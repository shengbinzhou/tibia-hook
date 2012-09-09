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

#ifndef CHANNELSPLUGININTERFACE_H
#define CHANNELSPLUGININTERFACE_H

#include <QtGlobal>
#include <QtPlugin>

class ChannelsPluginInterface {
public:
    virtual ~ChannelsPluginInterface() {}

    virtual quint16 openChannel(const QString& name) = 0;
    virtual void closeChannel(quint16 channelId) = 0;

    virtual void postMessage(quint16 channelId, const QString& message) = 0;
    virtual void postMessage(quint16 channelId, const QString& message, const QString& name) = 0;

    virtual void openPrivateChannel(const QString& name) = 0;
    virtual void postPrivateMessage(const QString& message, const QString& name) = 0;
};

Q_DECLARE_INTERFACE(ChannelsPluginInterface, "ChannelsPluginInterface")

#endif
