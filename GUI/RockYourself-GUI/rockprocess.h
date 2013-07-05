#ifndef ROCKPROCESS_H
#define ROCKPROCESS_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QProcess>
#include <QDebug>
#include <QDir>

class RockProcess : public QObject
{
    Q_OBJECT
public:
    explicit RockProcess(QObject *parent = 0);
    QProcess localProcess;
    void RipIt();
    
signals:
    void consoleOutput(QString);
    void finishedRipping();
    
public slots:
    void readyReadStandardOutput();
    void readyReadStandardError();
    void emitFinishedSignal(int);
};

#endif // ROCKPROCESS_H
