#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QApplication>

QString stack[10];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stack[1] = "stack";
    ui->Display->addItem(stack[1]);

    //this->ui->Input->installEventFilter(this); // This is part of Method 1

    //connect(ui->Enter, SIGNAL(released()), this, SLOT(EnterPressed()));
    connect(ui->Enter, SIGNAL(pressed()), this, SLOT(EnterPressed()));

    connect(ui->Input, SIGNAL(returnPressed()), this, SLOT(EnterPressed()));
    //connect(ui->Input, SIGNAL(returnPressed()), ui->Enter, SLOT(clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::EnterPressed(){
    //ui->Input->setText(QString("text"));
    ui->Display->clear();
    QString input = ui->Input->text();
    ui->Input->clear();
    ui->Display->addItem(input);
}

void MainWindow::BackspacePressed(){
    ui->Display->clear();
    ui->Input->clear();
    ui->Display->addItem(stack[1]);
}

//// -- Method 1: installEventFilter on Input object --------------------------------

//bool MainWindow::eventFilter(QObject *target, QEvent *event){
////     qDebug() << "Object: "
////              << (target!= Q_NULLPTR?target->objectName():"null")
////              << "EventType -> "
////              << QMetaEnum::fromType<QEvent::Type>().valueToKey((event != Q_NULLPTR?event->type():0));

//    if(target != this->ui->Input)
//        return false;
//    if(event->type() == QEvent::KeyPress){
//        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
//        if(keyEvent->key() == Qt::Key_Return){
//            qDebug() << "eventFilter: return pressed";
//            this->EnterPressed();
//            return true;
//        }
//    }
//    if(event->type() == QEvent::KeyRelease){
//        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
//        if(keyEvent->key() == Qt::Key_Return){
//            qDebug() << "eventFilter: return released";
//            return true;
//        }
//    }
//    return false;
//}

// -- Method 2: Rewrite keyPressEvent() function -------------------------------

void MainWindow::keyPressEvent(QKeyEvent *event){
    //qDebug() << "keyPressEvent Recieved";

    switch(event->key()){
        case Qt::Key_Return:
            qDebug() << "keyPressEvent: Return Pressed";
            EnterPressed();
            break;
        case Qt::Key_Enter:
            qDebug() << "KeyPressEvent: Enter Pressed";
            EnterPressed();
            break;
        case Qt::Key_Shift:
            qDebug() << "keyPressEvent: Shift Pressed";
            EnterPressed();
            break;
        case Qt::Key_Backspace:
            qDebug() << "keyPressEvent: Backspace Pressed";
            BackspacePressed();
            break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event){
    //qDebug() << "keyReleaseEvent Recieved";

    switch(event->key()){
        case Qt::Key_Return:
            qDebug() << "keyReleaseEvent: Return Released";
            //EnterPressed();
            break;
        case Qt::Key_Enter:
            qDebug() << "KeyReleaseEvent: Enter Released";
            //EnterPressed();
            break;
        case Qt::Key_Shift:
            qDebug() << "keyReleaseEvent: Shift Released";
            //EnterPressed();
            break;
        case Qt::Key_Backspace:
            qDebug() << "keyReleaseEvent: Backspace Released";
            //BackspacePressed();
            break;
        default:
            QWidget::keyReleaseEvent(event);
    }
}

// -- Method 3: Shortcuts (not yet implemented) --------------------------
