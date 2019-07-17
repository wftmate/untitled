#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QEvent>
#include <QApplication>
#include <iostream>

QString stack[10];
bool enterKeyTracker = false;

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

void MainWindow::EnterPressed(){
    //ui->Input->setText(QString("text"));

    ui->Display->clear();

    QString input = ui->Input->text();
    ui->Input->clear();

    ui->Display->addItem(input);

}

void MainWindow::EnterKeyPressed(){
    //enterKeyTracker = true;
    //qDebug() << "enterKeyTracker : " << enterKeyTracker;
    //EnterPressed();
    //ui->Display->clear();
}
