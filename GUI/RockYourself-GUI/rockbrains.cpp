// This stuff is from AKI.

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
    userInput->setText("Sherlock Holmes Complete Audiobook \nRobin Hood Chapter 1 Audio Book. \nHit Clear Button to clear these enteries.");

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


    this->setLayout(mainLayout);

    //QObject::connect(downloadButton, SIGNAL(clicked()), this, SLOT(getUserInput()));
    //QObject::connect(&rockProcess, SIGNAL(consoleOutput(QString)), this, SLOT(updateDownloadProgress(QString)));
    //QObject::connect(&rockProcess, SIGNAL(finishedRipping()), this, SLOT(finishedDownloading()));
    QObject::connect(clearButton, SIGNAL(clicked()), userInput, SLOT(clear()));


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
    //downloadProgress->clear();
    rockProcess.RipIt();

}

void RockBrains::updateDownloadProgress(QString updates) {
    //downloadProgress->append(updates);

}

void RockBrains::finishedDownloading() {
    userInput->setDisabled(false);
    //downloadButton->setDisabled(false);
    checkoutMessage->exec();

}
