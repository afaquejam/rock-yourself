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
#include <QWidget>
#include "rockprocess.h"

class RockBrains : public QWidget
{
    Q_OBJECT
public:
    explicit RockBrains(QWidget *parent = 0);
    QLabel *logoLabel;
    QLabel *infoLabel;
    QLabel *logLabel;
    QLabel *warningLabel;
    QTextEdit *userInput;
    QPushButton *downloadAudioButton;
    QPushButton *downloadVideoButton;
    QPushButton *showLogButton;
    QPushButton *helpButton;
    QPushButton *aboutButton;
    QCheckBox *isPopular;
    QVBoxLayout *mainLayout;
    QVBoxLayout *inputLayout;
    QVBoxLayout *buttonsLayout;
    QHBoxLayout *containerLayout;
    QHBoxLayout *logLayout;
    QMessageBox *checkoutMessage;
    QProgressBar *currentProgress;
    QPushButton *clearButton;
    QWidget *logWindow;
    QWidget *helpWindow;
    QWidget *aboutWindow;
    QLabel *logIcon;
    QLabel *helpLabel;
    QLabel *aboutLabel;
    QTextBrowser *logMessages;
    QTextBrowser *helpContent;
    QTextBrowser *aboutContent;
    QVBoxLayout *logWindowLayout;
    QVBoxLayout *helpWindowLayout;
    QVBoxLayout *aboutWindowLayout;
    RockProcess audioProcess;
    RockProcess videoProcess;
    int totalEnteries;
    int current;
    QStringList requestList;
    bool popular;

    
signals:
    void finishedAllQueries();
    void processFinished();
public slots:
    void getAudio();
    void getVideo();
    void getNextAudioQuery();
    void getNextVideoQuery();
    void updateDownloadProgress(QString);
    void finishedDownloading();
    bool processUserInput();
    void enableControls();
    void disableControls();
};

#endif // ROCKBRAINS_H
