// This stuff is from AKI.

#include "rockbrains.h"

RockBrains::RockBrains(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle("Rock Yourself Mates!");
    this->setMinimumSize(800, 800);

    QFont headingFont( "Arial", 30, QFont::Bold);
    QFont userInputFont( "Arial", 14);
    QFont buttonFont( "Arial", 20, QFont::Bold);


    mainLabel = new QLabel("Rock Yourself");
    mainLabel->setStyleSheet("qproperty-alignment: 'AlignCenter'");
    mainLabel->setFont(headingFont);

    userInput = new QTextEdit();
    userInput->setText("Enter your search queries here \n");
    userInput->setFont(userInputFont);

    downloadButton = new QPushButton("Let's Rock!");
    downloadButton->setFont(buttonFont);
    downloadButton->setMinimumHeight(75);

    downloadProgress = new QTextBrowser();
    downloadProgress->setText("Progress will be kinda shown here!");
    downloadProgress->setMaximumHeight(150);

    creditsLabel = new QLabel();
    creditsLabel->setText("Brought to you by AKI (Afaque)!");
    creditsLabel->setStyleSheet("qproperty-alignment: 'AlignLeft'");

    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(mainLabel);
    mainLayout->addWidget(userInput);
    mainLayout->addWidget(downloadButton);
    mainLayout->addWidget(downloadProgress);
    mainLayout->addWidget(creditsLabel);

    this->setLayout(mainLayout);

    QObject::connect(downloadButton, SIGNAL(clicked()), this, SLOT(getUserInput()));
    QObject::connect(&rockProcess, SIGNAL(consoleOutput(QString)), this, SLOT(updateDownloadProgress(QString)));


}

void RockBrains::getUserInput() {

    QString listLocation = QDir::homePath();
    listLocation.append("/Music/songlist");


    QFile file(listLocation);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream <<  userInput->toPlainText() << endl;
    }

    rockProcess.RipIt();

}

void RockBrains::updateDownloadProgress(QString updates) {
   downloadProgress->setText(updates);
}
