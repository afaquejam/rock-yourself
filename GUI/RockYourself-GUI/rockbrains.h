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
#include <QCheckBox>
#include <QProgressBar>
#include "rockprocess.h"

class RockBrains : public QWidget
{
    Q_OBJECT
public:
    explicit RockBrains(QWidget *parent = 0);
    QLabel *logoLabel;
    QLabel *infoLabel;
    QLabel *logLabel;
    QTextEdit *userInput;
    QPushButton *downloadAudioButton;
    QPushButton *downloadVideoButton;
    QPushButton *showLogButton;
    QPushButton *helpButton;
    QPushButton *aboutButton;
    QTextBrowser *downloadProgress;
    QCheckBox *isPopular;
    QVBoxLayout *mainLayout;
    QHBoxLayout *checkBoxLayout;
    QHBoxLayout *mediaButtonsLayout;
    QHBoxLayout *footerLayout;
    QMessageBox *checkoutMessage;
    QProgressBar *currentProgress;
    RockProcess rockProcess;
    
signals:
    
public slots:
    void getUserInput();
    void updateDownloadProgress(QString);
    void finishedDownloading();

};

#endif // ROCKBRAINS_H
