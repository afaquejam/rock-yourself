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
#include <QDesktopServices>

RockBrains::RockBrains(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle("Rock Yourself Mates!");
    this->setMinimumSize(800, 600);

    QFont buttonFont( "Arial", 16, QFont::Bold);

    logoLabel = new QLabel();
    logoLabel->setPixmap(QPixmap::fromImage(QImage(":image/Icons/Logo.png")));
    logoLabel->setStyleSheet("qproperty-alignment: 'AlignCenter'");

    infoLabel = new QLabel("List down the enteries below. See <b>Help</b> for more on how to use this software.");

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

    cancelDownloadButton = new QPushButton("Cancel Downloading");
    cancelDownloadButton->setIcon(QIcon(QPixmap::fromImage(QImage(":image/Icons/cancel.png"))));
    cancelDownloadButton->setMaximumSize(200, 50);
    cancelDownloadButton->hide();


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
    currentProgress->setTextVisible(true);
    currentProgress->hide();

    cancelLayout = new QHBoxLayout();
    cancelLayout->addWidget(cancelDownloadButton, Qt::AlignCenter);

    warningLabel = new QLabel();
    warningLabel->setText("By using this software, you agree to <b><u>Terms of Use</u></b> mentioned in the <b>About</b> section.");

    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(logoLabel);
    mainLayout->addLayout(containerLayout);
    mainLayout->addWidget(logLabel);
    mainLayout->addWidget(currentProgress);
    mainLayout->addLayout(cancelLayout);
    mainLayout->addWidget(warningLabel);

    logIcon = new QLabel();
    logIcon->setPixmap(QPixmap::fromImage(QImage(":image/Icons/Log_label.png")));
    logIcon->setStyleSheet("qproperty-alignment: 'AlignCenter'");

    logMessages = new QTextBrowser();
    logMessages->setText("Some kind Complete Log Messages will be shown here.");

    logWindowLayout = new QVBoxLayout();
    logWindowLayout->addWidget(logIcon);
    logWindowLayout->addWidget(logMessages);

    logWindow = new QWidget();
    logWindow->setLayout(logWindowLayout);
    logWindow->setMinimumSize(600, 400);

    helpLabel = new QLabel();
    helpLabel->setPixmap(QPixmap::fromImage(QImage(":image/Icons/help_label.png")));
    helpLabel->setStyleSheet("qproperty-alignment: 'AlignCenter'");

    QString helpText;
    helpText.append("<center> <h2><i>Using this Software is really simple.<i></h2></center><br>");
    helpText.append(" You can watch a short x minute video on how to use this software : <br><br>");
    helpText.append(" List down your enteries in the input box.");
    helpText.append(" For best results, enter first the artist name followed by the track name.");
    helpText.append(" For example, enter as follows: <br><br><i>Immortal beats oh wee <br> Jallacy Frozen Blades <br> Soda Eighteen Pieces</i> <br><br>");
    helpText.append("If you think your enteries are popular, then leave the <i>Popular Stuff</i> checkbox checked, else uncheck it. If you are downloading videos, then you shouldn't worry about this option. <br><br>");
    helpText.append(" You're ready to go! <b>Hit the 'Get Audio' or 'Get Video' button.</b> <br><br>");
    helpText.append(" Downloading will start and the progress will be shown on the bottom part of the window.");
    helpText.append(" After finishing the download, the software will prompt you to open the Music folder or the Videos folder, depending on whether you download audio or video.");
    helpText.append(" Audio files will be downloaded in the Music folder while the Videos will be downloaded in the Videos folder.");
    helpText.append(" You can view the log of your download in the Log window. <br> <br>");
    helpText.append(" That's it! If you have any questions, feel free to email me: <b><u>Afaque.Hussain@outlook.com</u></b> <br><br>");
    helpText.append(" <i> Cheers,<br><b>Afaque.</b></i> <br>");

    helpContent = new QTextBrowser();
    helpContent->setText(helpText);



    helpWindowLayout = new QVBoxLayout();
    helpWindowLayout->addWidget(helpLabel);
    helpWindowLayout->addWidget(helpContent);

    helpWindow = new QWidget();
    helpWindow->setLayout(helpWindowLayout);
    helpWindow->setMinimumSize(600, 400);

    aboutLabel = new QLabel();
    aboutLabel->setPixmap(QPixmap::fromImage(QImage(":image/Icons/about_label.png")));
    aboutLabel->setStyleSheet("qproperty-alignment: 'AlignCenter'");

    aboutContent = new QTextBrowser();
    aboutContent->setText("Something about me will be shown here.");

    aboutWindowLayout = new QVBoxLayout();
    aboutWindowLayout->addWidget(aboutLabel);
    aboutWindowLayout->addWidget(aboutContent);

    aboutWindow = new QWidget();
    aboutWindow->setLayout(aboutWindowLayout);
    aboutWindow->setMinimumSize(600, 400);

    this->setLayout(mainLayout);

    QObject::connect(downloadAudioButton, SIGNAL(clicked()), this, SLOT(getAudio()));
    QObject::connect(downloadVideoButton, SIGNAL(clicked()), this, SLOT(getVideo()));
    QObject::connect(clearButton, SIGNAL(clicked()), userInput, SLOT(clear()));
    QObject::connect(showLogButton, SIGNAL(clicked()), logWindow, SLOT(show()));
    QObject::connect(helpButton, SIGNAL(clicked()), helpWindow, SLOT(show()));
    QObject::connect(aboutButton, SIGNAL(clicked()), aboutWindow, SLOT(show()));

    QObject::connect(&audioProcess, SIGNAL(consoleOutput(QString)), this, SLOT(updateDownloadProgress(QString)));
    QObject::connect(&videoProcess, SIGNAL(consoleOutput(QString)), this, SLOT(updateDownloadProgress(QString)));
    QObject::connect(&audioProcess, SIGNAL(finishedRipping()), this, SLOT(getNextAudioQuery()));
    QObject::connect(&videoProcess, SIGNAL(finishedRipping()), this, SLOT(getNextVideoQuery()));

    QObject::connect(this, SIGNAL(finishedAllQueries()), this, SLOT(finishedDownloading()));
    QObject::connect(cancelDownloadButton, SIGNAL(clicked()), this, SLOT(cancelDownloading()));
}

void RockBrains::getAudio() {
    logMessages->clear();
    gettingAudio = true;
    processCanceled = false;

    if (processUserInput()) {
        disableControls();
        totalEnteries = requestList.size();
        current = -1;
        popular = isPopular->isChecked();
        getNextAudioQuery();
    }
}

void RockBrains::getVideo() {
    logMessages->clear();
    gettingAudio = false;
    processCanceled = false;

    if (processUserInput()) {
        disableControls();
        totalEnteries = requestList.size();
        current = -1;
        getNextVideoQuery();
    }
}

void RockBrains::updateDownloadProgress(QString updates) {
    logLabel->setText(updates);
    logMessages->append(updates);
}

void RockBrains::finishedDownloading() {

    enableControls();
    checkoutMessage = new QMessageBox();
    if(processCanceled) {
        checkoutMessage->setText(" Downloading Cancelled!");

    } else {
        if(gettingAudio) {
            checkoutMessage->setText("Got Audio files!");
            checkoutMessage->setInformativeText("Do you want to open the Music folder?");
            checkoutMessage->setStandardButtons(QMessageBox::Open | QMessageBox::Cancel);
            checkoutMessage->setDefaultButton(QMessageBox::Open);
            int userChoice = checkoutMessage->exec();

            if(userChoice == QMessageBox::Open) {
                QDesktopServices::openUrl(QUrl(QDesktopServices::storageLocation(QDesktopServices::MusicLocation)));
            }

        } else {
            checkoutMessage->setText("Got Video files!");
            checkoutMessage->setInformativeText("Do you want to open the Videos folder?");
            checkoutMessage->setStandardButtons(QMessageBox::Open | QMessageBox::Cancel);
            checkoutMessage->setDefaultButton(QMessageBox::Open);
            int userChoice = checkoutMessage->exec();

            if(userChoice == QMessageBox::Open) {
                QDesktopServices::openUrl(QUrl(QDesktopServices::storageLocation(QDesktopServices::MoviesLocation)));
            }
        }
    }
}

void RockBrains::getNextAudioQuery() {
    current++;

    if (current < totalEnteries && !processCanceled) {
        QString request = requestList.at(current);
        qDebug()<<request;
        QString progressBarText(" Downloading " + QString::number(current+1) + " of " + QString::number(totalEnteries) + " ... ");
        currentProgress->setFormat(progressBarText);
        currentProgress->setValue((((current+1)*100)/totalEnteries)-1);
        audioProcess.getAudio(request, popular);

        // Only for testing purposes, Uncomment the above line before the commit.
        //getNextAudioQuery();
        // Testing

    } else {
        emit finishedAllQueries();
    }
}

void RockBrains::getNextVideoQuery() {
    current++;
    if (current < totalEnteries && !processCanceled) {
        QString request = requestList.at(current);
        qDebug()<<request;
        QString progressBarText(" Downloading " + QString::number(current+1) + " of " + QString::number(totalEnteries) + " ... ");
        currentProgress->setFormat(progressBarText);
        currentProgress->setValue((((current+1)*100)/totalEnteries)-1);
        videoProcess.getVideo(request);

        // Only for testing purposes, Uncomment the above line before the commit.
        //getNextVideoQuery();
        // Testing
    } else {
        emit finishedAllQueries();
    }

}

bool RockBrains::processUserInput() {
    requestList.clear();

    if (!userInput->toPlainText().replace(QRegExp("\\s+"),"").isEmpty()) {
        QStringList bufferList = userInput->toPlainText().split("\n");

        for (int i=0; i<bufferList.size(); i++) {
            QString request = bufferList.at(i);
            request = request.replace(QRegExp("\\s+"),"+");
            if (!(QString::compare(request, "+") == 0 || request.isEmpty())) {
                requestList.append(request);
            }
        }
        return true;
    } else {
        QMessageBox *noInputMessage = new QMessageBox();
        noInputMessage->setText("You're fooling around mate!");
        logMessages->setText("Nothing was entered. You're fooling around mate.");
        noInputMessage->exec();
        userInput->clear();
        return false;
    }
}

void RockBrains::enableControls() {
    logLabel->hide();
    currentProgress->hide();
    cancelDownloadButton->hide();

    userInput->setDisabled(false);
    isPopular->setDisabled(false);
    downloadAudioButton->setDisabled(false);
    downloadVideoButton->setDisabled(false);
    clearButton->setDisabled(false);
    showLogButton->setDisabled(false);
    warningLabel->show();
}

void RockBrains::disableControls() {
    logLabel->show();
    currentProgress->show();
    cancelDownloadButton->show();

    userInput->setDisabled(true);
    isPopular->setDisabled(true);
    downloadAudioButton->setDisabled(true);
    downloadVideoButton->setDisabled(true);
    clearButton->setDisabled(true);
    showLogButton->setDisabled(true);
    warningLabel->hide();
}

void RockBrains::cancelDownloading() {
    processCanceled = true;
    logMessages->setText(" Downloading Cancelled!");
    if(gettingAudio) {
        audioProcess.killProcess();
    } else {
        videoProcess.killProcess();
    }
}
