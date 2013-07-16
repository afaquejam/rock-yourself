/*
  * A simple project to reduce the pain of getting (more than one & mostly interesting) stuff
  * from the internet by eliminating the need of URLs as much as possible.
  * By stuff here, we mean the content which has been shared under Creative Commons License or as free.
  *
  * Project : Rock-Yourself
  * Code by : Afaque "AKI" Hussain
  * Contact : Afaque.Hussain@outlook.com
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * any later version.

  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.

  * Please read the GNU General Public License at <http://www.gnu.org/licenses/>.
  */


#include <QApplication>
#include "rockbrains.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RockBrains mainWindow;
    mainWindow.show();

    return a.exec();
}
