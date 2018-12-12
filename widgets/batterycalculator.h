/*
    Copyright 2016 - 2017 Benjamin Vedder	benjamin@vedder.se

    

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

#ifndef BATTERYCALCULATOR_H
#define BATTERYCALCULATOR_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class BatteryCalculator;
}

class BatteryCalculator : public QWidget
{
    Q_OBJECT

public:
    explicit BatteryCalculator(QWidget *parent = 0);
    ~BatteryCalculator();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void on_batteryCalcButton_clicked();
    void on_batteryCellBox_valueChanged(int arg1);
    void on_batteryTypeBox_currentIndexChanged(int index);
    void on_helpButton_clicked();

private:
    Ui::BatteryCalculator *ui;
    VescInterface *mVesc;
    double mValStart;
    double mValEnd;

    void calc();

};

#endif // BATTERYCALCULATOR_H
