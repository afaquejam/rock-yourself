// This stuff is from AKI.


#include <QApplication>
#include "rockbrains.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RockBrains mainWindow;
    mainWindow.show();

    return a.exec();
}
