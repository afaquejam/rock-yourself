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

void RockProcess::emitFinishedSignal(int exitCode) {
    emit finishedRipping();
}
