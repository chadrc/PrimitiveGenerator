#include "mainwindow.h"
#include <QApplication>
#include <QtGlobal>
#include <QTime>

int main(int argc, char *argv[])
{
    qsrand(QTime::currentTime().second());
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
