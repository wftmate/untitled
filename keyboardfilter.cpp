#include "keyboardfilter.h"
#include "mainwindow.h"
#include <QDebug>

bool KeyboardFilter::eventFilter(QObject *target, QEvent *event){
    if(event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

        if(keyEvent->key() == Qt::Key_Return){ // this one doesn't work for some reason
            qDebug() << "Return Pressed";
            MainWindow::EnterKeyPressed();
            MainWindow::ui->Display->clear();
            return true;
        }

        if(keyEvent->key() == Qt::Key_Enter){
            qDebug() << "Enter Pressed";
            MainWindow::EnterKeyPressed();
            return true;
        }
    }

//    if(event->type() == QEvent::KeyRelease){
//        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

//        if(keyEvent->key() == Qt::Key_Return){
//            qDebug() << "Return Released";
//            MainWindow::EnterKeyPressed();
//            return true;
//        }

//        if(keyEvent->key() == Qt::Key_Enter){
//            qDebug() << "Enter Released";
//            MainWindow::EnterKeyPressed();
//            return true;
//        }
//    }
    return false;
}
