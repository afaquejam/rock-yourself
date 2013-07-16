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


#include "rockbrains.h"

RockBrains::RockBrains(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle("Rock Yourself Mates!");
    this->setMinimumSize(800, 600);

    QFont buttonFont( "Arial", 16, QFont::Bold);

    logoLabel = new QLabel();
    logoLabel->setPixmap(QPixmap::fromImage(QImage(":image/Icons/Logo.png")));
    logoLabel->setStyleSheet("qproperty-alignment: 'AlignCenter'");

    infoLabel = new QLabel("Write below the list of stuff that you would like to have as shown: ");

    userInput = new QTextEdit();

    inputLayout = new QVBoxLayout();
    inputLayout->addWidget(infoLabel);
    inputLayout->addWidget(userInput);

    isPopular = new QCheckBox("Popular Stuff");
    isPopular->setChecked(true);

    downloadAudioButton = new QPushButton("Get Audio");
    downloadAudioButton->setIcon(QIcon(QPixmap::fromImage(QImage(":image/Icons/audio.png"))));
    downloadAudioButton->setMinimumSize(200, 50);

    downloadVideoButton = new QPushButton("Get Video");
    downloadVideoButton->setIcon(QIcon(QPixmap::fromImage(QImage(":image/Icons/video.png"))));
    downloadVideoButton->setMinimumSize(200, 50);

    clearButton = new QPushButton("Clear");
    clearButton->setIcon(QIcon(QPixmap::fromImage(QImage(":image/Icons/clear.png"))));
    clearButton->setMinimumSize(200, 50);

    showLogButton = new QPushButton("Show Log");
    showLogButton->setIcon(QIcon(QPixmap::fromImage(QImage(":image/Icons/log.png"))));
    showLogButton->setMinimumSize(200, 50);

    helpButton = new QPushButton("Help");
    helpButton->setIcon(QIcon(QPixmap::fromImage(QImage(":image/Icons/help.png"))));
    helpButton->setMinimumSize(200, 50);

    aboutButton = new QPushButton("About");
    aboutButton->setIcon(QIcon(QPixmap::fromImage(QImage(":image/Icons/about.png"))));
    aboutButton->setMinimumSize(200, 50);

    buttonsLayout = new QVBoxLayout();
    buttonsLayout->addWidget(isPopular);
    buttonsLayout->addWidget(downloadAudioButton);
    buttonsLayout->addWidget(downloadVideoButton);
    buttonsLayout->addWidget(clearButton);
    buttonsLayout->addWidget(showLogButton);
    buttonsLayout->addWidget(helpButton);
    buttonsLayout->addWidget(aboutButton);

    containerLayout = new QHBoxLayout();
    containerLayout->addLayout(inputLayout);
    containerLayout->addLayout(buttonsLayout);

    logLabel = new QLabel("Current Progress will be shown here.");
    logLabel->hide();

    currentProgress = new QProgressBar();
    currentProgress->hide();

    warningLabel = new QLabel();
    warningLabel->setText("WARNING! Be careful of what you download using this software. The developer of this software is not responsible for any misuse of this software.");

    //downloadProgress = new QTextBrowser();
    //downloadProgress->setText("Progress will be kinda shown here!");
    //downloadProgress->setMaximumHeight(150);

    checkoutMessage = new QMessageBox();
    checkoutMessage->setText("If the log messages didn't say anything bad then check out the Music folder in your home directory. You may find some stuff there :). ");


    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(logoLabel);
    mainLayout->addLayout(containerLayout);
    mainLayout->addWidget(logLabel);
    mainLayout->addWidget(currentProgress);
    mainLayout->addWidget(warningLabel);

    logIcon = new QLabel("Log");
    logMessages = new QTextBrowser();
    logMessages->setText("Some kind Complete Log Messages will be shown here.");

    logWindowLayout = new QVBoxLayout();
    logWindowLayout->addWidget(logIcon);
    logWindowLayout->addWidget(logMessages);

    logWindow = new QWidget();
    logWindow->setLayout(logWindowLayout);
    logWindow->setMinimumSize(600, 400);

    helpLabel = new QLabel("Help");
    helpContent = new QTextBrowser();
    helpContent->setText("Some kind of help will be shown here.");

    helpWindowLayout = new QVBoxLayout();
    helpWindowLayout->addWidget(helpLabel);
    helpWindowLayout->addWidget(helpContent);

    helpWindow = new QWidget();
    helpWindow->setLayout(helpWindowLayout);
    helpWindow->setMinimumSize(600, 400);

    aboutLabel = new QLabel("About");
    aboutContent = new QTextBrowser();
    aboutContent->setText("Something about me will be shown here.");

    aboutWindowLayout = new QVBoxLayout();
    aboutWindowLayout->addWidget(aboutLabel);
    aboutWindowLayout->addWidget(aboutContent);

    aboutWindow = new QWidget();
    aboutWindow->setLayout(aboutWindowLayout);
    aboutWindow->setMinimumSize(600, 400);

    this->setLayout(mainLayout);



    //QObject::connect(&rockProcess, SIGNAL(finishedRipping()), this, SLOT(finishedDownloading()));

    QObject::connect(&rockProcess, SIGNAL(consoleOutput(QString)), this, SLOT(updateDownloadProgress(QString)));
    QObject::connect(downloadAudioButton, SIGNAL(clicked()), this, SLOT(getAudio()));
    QObject::connect(clearButton, SIGNAL(clicked()), userInput, SLOT(clear()));
    QObject::connect(showLogButton, SIGNAL(clicked()), logWindow, SLOT(show()));
    QObject::connect(helpButton, SIGNAL(clicked()), helpWindow, SLOT(show()));
    QObject::connect(aboutButton, SIGNAL(clicked()), aboutWindow, SLOT(show()));


}

void RockBrains::getAudio() {

    logLabel->show();
    currentProgress->show();
    userInput->setDisabled(true);
    isPopular->setDisabled(true);
    downloadAudioButton->setDisabled(true);
    downloadVideoButton->setDisabled(true);
    clearButton->setDisabled(true);
    showLogButton->setDisabled(true);
    // Still have to handle the case where user just enters bunch of spaces and line breaks.

    QStringList requestList = userInput->toPlainText().split("\n");
    int numberOfEnteries = requestList.size();
    qDebug()<< numberOfEnteries;
    for( int i=0; i < numberOfEnteries; i++) {
        QString request = requestList.at(i);
        rockProcess.getAudio(request);

    }

    logLabel->hide();
    currentProgress->hide();
    userInput->setDisabled(false);
    isPopular->setDisabled(false);
    downloadAudioButton->setDisabled(false);
    downloadVideoButton->setDisabled(false);
    clearButton->setDisabled(false);
    showLogButton->setDisabled(false);


}

void RockBrains::updateDownloadProgress(QString updates) {
    logLabel->setText(updates);
    logMessages->append(updates);


}

void RockBrains::finishedDownloading() {
    userInput->setDisabled(false);
    //downloadButton->setDisabled(false);
    checkoutMessage->exec();

}