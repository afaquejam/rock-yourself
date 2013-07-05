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
    QVBoxLayout *mainLayout;
    RockProcess rockProcess;
    
signals:
    
public slots:
    void getUserInput();
    void updateDownloadProgress(QString);

};

#endif // ROCKBRAINS_H
