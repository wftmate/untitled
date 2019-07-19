#include "mainwindow2.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QApplication>

QString stack[10];

MainWindow2::MainWindow2()
{

    ui->setupUi(this);

    stack[1] = "stack";
    ui->Display->addItem(stack[1]);

    this->ui->Input->installEventFilter(this);

    connect(ui->Enter, SIGNAL(released()), this, SLOT(EnterPressed()));

}
MainWindow2::~MainWindow()
{
    delete ui;
}

void MainWindow2::EnterPressed(){
    //ui->Input->setText(QString("text"));
    ui->Display->clear();
    QString input = ui->Input->text();
    ui->Input->clear();
    ui->Display->addItem(input);
}

void MainWindow2::BackspacePressed(){
    ui->Display->clear();
    ui->Input->clear();
    ui->Display->addItem(stack[1]);
}

//void MainWindow2::keyPressEvent(QKeyEvent *event){
//    //qDebug() << "keyPressEvent Recieved";

//    switch(event->key()){
//        case Qt::Key_Return:
//            qDebug() << "keyPressEvent: Return Pressed";
//            EnterPressed();
//            break;
//        case Qt::Key_Enter:
//            qDebug() << "KeyPressEvent: Enter Pressed";
//            EnterPressed();
//            break;
//        case Qt::Key_Shift:
//            qDebug() << "keyPressEvent: Shift Pressed";
//            EnterPressed();
//            break;
//        case Qt::Key_Backspace:
//            qDebug() << "keyPressEvent: Backspace Pressed";
//            BackspacePressed();
//            break;
//    }
//}

//void MainWindow2::keyReleaseEvent(QKeyEvent *event){
//    //qDebug() << "keyReleaseEvent Recieved";

//    switch(event->key()){
//        case Qt::Key_Return:
//            qDebug() << "keyReleaseEvent: Return Released";
//            //EnterPressed();
//            break;
//        case Qt::Key_Enter:
//            qDebug() << "KeyReleaseEvent: Enter Released";
//            //EnterPressed();
//            break;
//        case Qt::Key_Shift:
//            qDebug() << "keyReleaseEvent: Shift Released";
//            //EnterPressed();
//            break;
//        case Qt::Key_Backspace:
//            qDebug() << "keyReleaseEvent: Backspace Released";
//            //BackspacePressed();
//            break;
//        default:
//            QWidget::keyReleaseEvent(event);
//    }
//}
