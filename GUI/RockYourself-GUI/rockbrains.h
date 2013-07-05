#ifndef ROCKBRAINS_H
#define ROCKBRAINS_H

#include <QWidget>
#include<QTextEdit>
#include <QProgressBar>
#include <QProcess>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>


class RockBrains : public QWidget
{
    Q_OBJECT
public:
    explicit RockBrains(QWidget *parent = 0);
    QLabel *mainLabel;
    QTextEdit *userInput;
    QPushButton *downloadButton;
    QProgressBar *downloadProgress;
    QLabel *creditsLabel;
    QVBoxLayout *mainLayout;


    
signals:
    
public slots:
    void getUserInput();
    
};

#endif // ROCKBRAINS_H
