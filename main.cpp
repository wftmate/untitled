#include "mainwindow.h"
#include "keyboardfilter.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    KeyboardFilter* key = new KeyboardFilter();
    w.installEventFilter(key);

    return a.exec();
}
