#include "rockbrains.h"
#include <QFile>
#include <QTextStream>
#include <QDir>

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

    downloadProgress = new QProgressBar();
    downloadProgress->hide();

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
}

void RockBrains::getUserInput() {

    QString listLocation = QDir::homePath();
    listLocation.append("/Music/songlist");

        QFile file(listLocation);
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream <<  userInput->toPlainText() << endl;
        }

        downloadProgress->setValue(50);
        downloadProgress->show();

}
