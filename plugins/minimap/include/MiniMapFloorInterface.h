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

#ifndef MINIMAPFLOORINTERFACE_H
#define MINIMAPFLOORINTERFACE_H

#include "MiniMapPartInterface.h"

#include <QList>
#include <QRect>

class MiniMapFloorInterface {
public:
    virtual ~MiniMapFloorInterface() {}

    virtual const QList<MiniMapPartInterface*>& parts() = 0;
    virtual const QRect& boundary() const = 0;
    virtual quint8 z() const = 0;

    virtual QRgb colorAt(quint16 x, quint16 y) const = 0;
    virtual quint8 dataAt(quint16 x, quint16 y) const = 0;
};

#endif
