#include "mainwindow.h"
#include "keyboardfilter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    KeyboardFilter* key = new KeyboardFilter();
    w.installEventFilter(key);

    if(key){
        w.EnterPressed();
    }

//    KeyboardFilter filter;
//    a.installEventFilter(&filter);

//    if(&filter){
//        w.EnterPressed();
//    }

    return a.exec();
}
