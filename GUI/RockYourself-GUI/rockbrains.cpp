// This stuff is from AKI.

#include "rockbrains.h"

RockBrains::RockBrains(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle("Rock Yourself Mates!");
    this->setMinimumSize(800, 600);

    QFont headingFont( "Arial", 30, QFont::Bold);
    QFont userInputFont( "Arial", 14);
    QFont buttonFont( "Arial", 20, QFont::Bold);

    mainLabel = new QLabel("Rock Yourself");
    mainLabel->setStyleSheet("qproperty-alignment: 'AlignCenter'");
    mainLabel->setFont(headingFont);

    userInput = new QTextEdit();
    userInput->setText("linkin park in the end \nfall out boy light em up \n");
    userInput->setFont(userInputFont);

    downloadButton = new QPushButton("Let's Rock!");
    downloadButton->setFont(buttonFont);
    downloadButton->setMinimumHeight(75);

    downloadProgress = new QTextBrowser();
    downloadProgress->setText("Progress will be kinda shown here!");
    downloadProgress->setMaximumHeight(150);

    inputLabel = new QLabel("Write the stuff that you want below:");


    creditsLabel = new QLabel();
    creditsLabel->setText("Brought to you by AKI (Afaque)!");
    creditsLabel->setStyleSheet("qproperty-alignment: 'AlignLeft'");

    logLabel = new QLabel("Check the progress below:");

    checkoutMessage = new QMessageBox();
    checkoutMessage->setText("If the log messages didn't say anything bad then check out the Music folder in your home directory. You may find some stuff there :). ");


    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(mainLabel);
    mainLayout->addWidget(inputLabel);
    mainLayout->addWidget(userInput);
    mainLayout->addWidget(downloadButton);
    mainLayout->addWidget(logLabel);
    mainLayout->addWidget(downloadProgress);
    mainLayout->addWidget(creditsLabel);

    this->setLayout(mainLayout);

    QObject::connect(downloadButton, SIGNAL(clicked()), this, SLOT(getUserInput()));
    QObject::connect(&rockProcess, SIGNAL(consoleOutput(QString)), this, SLOT(updateDownloadProgress(QString)));
    QObject::connect(&rockProcess, SIGNAL(finishedRipping()), this, SLOT(finishedDownloading()));


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
    downloadButton->setDisabled(true);
    downloadProgress->clear();
    rockProcess.RipIt();

}

void RockBrains::updateDownloadProgress(QString updates) {
    downloadProgress->append(updates);

}

void RockBrains::finishedDownloading() {
    userInput->setDisabled(false);
    downloadButton->setDisabled(false);
    checkoutMessage->exec();

}
