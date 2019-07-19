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

    this->ui->Input->installEventFilter(this);

    connect(ui->Enter, SIGNAL(released()), this, SLOT(EnterPressed()));
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

bool MainWindow::eventFilter(QObject *target, QEvent *event){
    if(target != this->ui->Input)
        return false;
    if(event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if(keyEvent->key() == Qt::Key_Return){
            qDebug() << "return pressed";
            this->EnterPressed();
            return true;
        }
    }
    if(event->type() == QEvent::KeyRelease){
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if(keyEvent->key() == Qt::Key_Return){
            qDebug() << "return released";
            return true;
        }
    }
    return false;
}

