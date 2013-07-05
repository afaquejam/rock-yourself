// This stuff is from AKI.

#ifndef ROCKBRAINS_H
#define ROCKBRAINS_H

#include <QWidget>
#include<QTextEdit>
#include <QTextBrowser>
#include <QProcess>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QStringList>
#include <QMessageBox>
#include "rockprocess.h"

class RockBrains : public QWidget
{
    Q_OBJECT
public:
    explicit RockBrains(QWidget *parent = 0);
    QLabel *mainLabel;
    QTextEdit *userInput;
    QPushButton *downloadButton;
    QTextBrowser *downloadProgress;
    QLabel *creditsLabel;
    QLabel *inputLabel;
    QLabel *logLabel;
    QVBoxLayout *mainLayout;
    QMessageBox *checkoutMessage;
    RockProcess rockProcess;
    
signals:
    
public slots:
    void getUserInput();
    void updateDownloadProgress(QString);
    void finishedDownloading();

};

#endif // ROCKBRAINS_H
