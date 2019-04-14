/*
    Copyright 2017 Benjamin Vedder	benjamin@vedder.se



    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program .  If not, see <http://www.gnu.org/licenses/>.
    */

#ifndef UTILITY_H
#define UTILITY_H

#include <QObject>
#include <QMetaEnum>
#include <cstdint>
#include "vescinterface.h"

class Utility : public QObject
{
    Q_OBJECT

public:
    explicit Utility(QObject *parent = nullptr);

    static double map(double x, double in_min, double in_max, double out_min, double out_max);
    Q_INVOKABLE static float throttle_curve(float val, float curve_acc, float curve_brake, int mode);
    static bool autoconnectBlockingWithProgress(VescInterface *vesc, QWidget *parent = 0);
    Q_INVOKABLE static void checkVersion(VescInterface *vesc = 0);
    Q_INVOKABLE static QString fwChangeLog();
    Q_INVOKABLE static QString vescToolChangeLog();
    Q_INVOKABLE static QString aboutText();
    Q_INVOKABLE static QString uuid2Str(QByteArray uuid, bool space);
    Q_INVOKABLE static bool requestFilePermission();
    static uint32_t crc32c(uint8_t *data, uint32_t len);

    template<typename QEnum>
       static QString QEnumToQString (const QEnum value) {
           return QString(QMetaEnum::fromType<QEnum>().valueToKey(value));
       }

signals:

public slots:
};

#endif // UTILITY_H
