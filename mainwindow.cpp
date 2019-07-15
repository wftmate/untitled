#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QKeyEvent>

QString stack[10];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stack[1] = "stack";
    ui->Display->addItem(stack[1]);

    connect(ui->Enter, SIGNAL(released()), this, SLOT(EnterPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//qDebug() << "Debug Message";
//QDebug("text");

void MainWindow::EnterPressed(){
    //ui->Input->setText(QString("text"));

    ui->Display->clear();

    QString input = ui->Input->text();
    ui->Input->clear();

    ui->Display->addItem(input);
}

void MainWindow::KeyPressEvent(QKeyEvent *event){

    QString temp = "temp string";
    ui->Display->addItem(temp);

    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return
            || event->key() == 0x13 || event->key() == 0x01000004)
    {
        EnterPressed();

        QString inputValue = ui->Input->text();
        ui->Display->addItem(inputValue);
    }
}

void MainWindow::KeyReleaseEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Enter)
    {
        EnterPressed();
    }
}

bool MainWindow::EventFilter(QEvent *event){

    bool handled = false;
    if(event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = (QKeyEvent *)event;

        if(keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter){
            MainWindow::EnterPressed();
        }
    }
    return handled;
}

