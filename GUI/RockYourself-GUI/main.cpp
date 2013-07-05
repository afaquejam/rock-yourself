// This stuff is from AKI.


#include <QApplication>
#include<QTextEdit>
#include <QProgressBar>
#include <QProcess>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget mainWindow;

    mainWindow.setWindowTitle("Rock Yourself Mates!");
    mainWindow.setMinimumSize(800, 800);

    QFont headingFont( "Arial", 30, QFont::Bold);
    QFont userInputFont( "Arial", 14);
    QFont buttonFont( "Arial", 20, QFont::Bold);


    QLabel *mainLabel = new QLabel("Rock Yourself");
    mainLabel->setStyleSheet("qproperty-alignment: 'AlignCenter'");
    mainLabel->setFont(headingFont);

    QTextEdit *userInput = new QTextEdit();
    userInput->setText("Enter your search queries here \n");
    userInput->setFont(userInputFont);

    QPushButton *downloadButton = new QPushButton("Let's Rock!");
    downloadButton->setFont(buttonFont);
    downloadButton->setMinimumHeight(75);

    QProgressBar *downloadProgress = new QProgressBar();
    downloadProgress->hide();

    QLabel *creditsLabel = new QLabel();
    creditsLabel->setText("Brought to you by AKI (Afaque)!");
    creditsLabel->setStyleSheet("qproperty-alignment: 'AlignLeft'");

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(mainLabel);
    mainLayout->addWidget(userInput);
    mainLayout->addWidget(downloadButton);
    mainLayout->addWidget(downloadProgress);
    mainLayout->addWidget(creditsLabel);

    mainWindow.setLayout(mainLayout);
    mainWindow.show();

    return a.exec();
}
