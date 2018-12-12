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

#ifndef PAGETERMINAL_H
#define PAGETERMINAL_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageTerminal;
}

class PageTerminal : public QWidget
{
    Q_OBJECT

public:
    explicit PageTerminal(QWidget *parent = 0);
    ~PageTerminal();
    void clearTerminal();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void printReceived(QString str);

    void on_sendButton_clicked();
    void on_helpButton_clicked();

private:
    Ui::PageTerminal *ui;
    VescInterface *mVesc;

};

#endif // PAGETERMINAL_H
