#include "mainwindow.h"
#include "keyboardfilter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    KeyboardFilter filter;
    w.installEventFilter(&filter);

    return a.exec();
}
