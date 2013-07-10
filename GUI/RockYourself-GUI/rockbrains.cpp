// This stuff is from AKI.

#include "rockbrains.h"

RockBrains::RockBrains(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle("Rock Yourself Mates!");
    this->setMinimumSize(800, 600);

    QFont buttonFont( "Arial", 20, QFont::Bold);

    logoLabel = new QLabel();
    logoLabel->setPixmap(QPixmap::fromImage(QImage(":image/Icons/FL.png")));
    logoLabel->setStyleSheet("qproperty-alignment: 'AlignCenter'");

    infoLabel = new QLabel("Write the stuff that you want below:");
    isPopular = new QCheckBox("Popular");
    isPopular->setChecked(true);

    checkBoxLayout = new QHBoxLayout();
    checkBoxLayout->addWidget(infoLabel);
    checkBoxLayout->addWidget(isPopular);

    userInput = new QTextEdit();

    downloadAudioButton = new QPushButton("Get Audio");
    downloadAudioButton->setIcon(QIcon(QPixmap::fromImage(QImage(":image/Icons/audio.png"))));
    //downloadAudioButton->setFont(buttonFont);

    downloadVideoButton = new QPushButton("Get Video");
    downloadVideoButton->setIcon(QIcon(QPixmap::fromImage(QImage(":image/Icons/video.png"))));
    //downloadVideoButton->setFont(buttonFont);

    mediaButtonsLayout = new QHBoxLayout();
    mediaButtonsLayout->addWidget(downloadAudioButton);
    mediaButtonsLayout->addWidget(downloadVideoButton);

    showLogButton = new QPushButton("Show Log");
    showLogButton->setIcon(QIcon(QPixmap::fromImage(QImage(":image/Icons/log.png"))));

    logLabel = new QLabel("Current Progress will be shown here.");
    logLabel->hide();

    currentProgress = new QProgressBar();
    currentProgress->hide();

    helpButton = new QPushButton("Help");
    helpButton->setIcon(QIcon(QPixmap::fromImage(QImage(":image/Icons/help.png"))));


    aboutButton = new QPushButton("About");
    aboutButton->setIcon(QIcon(QPixmap::fromImage(QImage(":image/Icons/about.png"))));


    footerLayout = new QHBoxLayout();
    footerLayout->addWidget(helpButton);
    footerLayout->addWidget(aboutButton);

    //downloadProgress = new QTextBrowser();
    //downloadProgress->setText("Progress will be kinda shown here!");
    //downloadProgress->setMaximumHeight(150);

    checkoutMessage = new QMessageBox();
    checkoutMessage->setText("If the log messages didn't say anything bad then check out the Music folder in your home directory. You may find some stuff there :). ");


    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(logLabel);
    mainLayout->addLayout(checkBoxLayout);
    mainLayout->addWidget(userInput);
    mainLayout->addLayout(mediaButtonsLayout);
    mainLayout->addWidget(logLabel);
    mainLayout->addWidget(currentProgress);
    mainLayout->addLayout(footerLayout);

    this->setLayout(mainLayout);

    //QObject::connect(downloadButton, SIGNAL(clicked()), this, SLOT(getUserInput()));
    //QObject::connect(&rockProcess, SIGNAL(consoleOutput(QString)), this, SLOT(updateDownloadProgress(QString)));
    //QObject::connect(&rockProcess, SIGNAL(finishedRipping()), this, SLOT(finishedDownloading()));


}

void RockBrains::getUserInput() {

    QString listLocation = QDir::homePath();
    listLocation.append("/Music/songlist");


    QFile file(listLocation);

    if(file.exists()) {
        QFile::remove(listLocation);
    }

    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream <<  userInput->toPlainText() << endl;
    }

    userInput->setDisabled(true);
    //downloadButton->setDisabled(true);
    downloadProgress->clear();
    rockProcess.RipIt();

}

void RockBrains::updateDownloadProgress(QString updates) {
    downloadProgress->append(updates);

}

void RockBrains::finishedDownloading() {
    userInput->setDisabled(false);
    //downloadButton->setDisabled(false);
    checkoutMessage->exec();

}
