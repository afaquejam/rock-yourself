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


#include "rockprocess.h"

RockProcess::RockProcess(QObject *parent) :
    QObject(parent)
{

    connect(&localProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadStandardOutput()));
    connect(&localProcess,SIGNAL(readyReadStandardError()),this,SLOT(readyReadStandardError()));
    connect(&localProcess, SIGNAL(finished(int)), this, SLOT(emitFinishedSignal(int)));
}

void RockProcess::readyReadStandardOutput(){
    //qDebug()<< localProcess.readAllStandardOutput();
    QString log(localProcess.readAllStandardOutput());
    qDebug() << log;
    emit consoleOutput(log);
}

void RockProcess::readyReadStandardError(){
    //qDebug() << localProcess.readAllStandardError();
    QString log(localProcess.readAllStandardError());
    qDebug() << log;
    emit consoleOutput(log);
}

void RockProcess::getAudio(QString argument, bool popular) {
    QString program = "rock-music";

    QString workingLocation = QDir::homePath();
    workingLocation.append("/Music");
    QDir::setCurrent(workingLocation);

    QStringList arguments;
    if (popular) {
        arguments<< "1";
    } else {
        arguments<< "0";
    }

    arguments << argument;
    localProcess.start(program, arguments);


}

void RockProcess::getVideo(QString argument) {
    QString program = "rock-video";

    QString workingLocation = QDir::homePath();
    workingLocation.append("/Videos");
    QDir::setCurrent(workingLocation);

    QStringList arguments;
    arguments << argument;
    localProcess.start(program, arguments);
}

void RockProcess::emitFinishedSignal(int exitCode) {
    emit finishedRipping();
}
