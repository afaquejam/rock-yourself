#include "rockprocess.h"

RockProcess::RockProcess(QObject *parent) :
    QObject(parent)
{

    connect(&localProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadStandardOutput()));
    connect(&localProcess,SIGNAL(readyReadStandardError()),this,SLOT(readyReadStandardError()));
}

void RockProcess::readyReadStandardOutput(){
    qDebug()<< localProcess.readAllStandardOutput();
    QString output = localProcess.readAllStandardOutput();
    emit consoleOutput(output);
}

void RockProcess::readyReadStandardError(){
    qDebug() << localProcess.readAllStandardError();
    QString output = localProcess.readAllStandardError();
    emit consoleOutput(output);
}

void RockProcess::RipIt() {

    QString program = "rockyourself";
    QString workingLocation = QDir::homePath();
    workingLocation.append("/Music");
    QDir::setCurrent(workingLocation);

    QString songlistLocation = workingLocation;
    songlistLocation.append("/songlist");

    QStringList arguments;
    arguments << songlistLocation;
    localProcess.start(program, arguments);
}
