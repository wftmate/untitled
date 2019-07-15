#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QKeyEvent>
#include <iostream>

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


// -- Attempt 1 to catch "Enter"/"Return" key ---

void MainWindow::KeyPressEvent(QKeyEvent *event){
    std::cout << "Key Pressed";
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

// -- Attempt 1 to catch "Enter"/"Return" key ---


// -- Attempt 2 to catch "Enter"/"Return" key --- I think this one is better

// Define event filter class - this probably belongs in a different .cpp file
class keyEnterReceiver : public QObject
{
    Q_OBJECT
protected:
    bool eventFilter(QObject* obj, QEvent* event);
};

// Define what the eventFilter function beloning to the keyEnterReciever class does
bool keyEnterReceiver::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type()==QEvent::KeyPress) {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        if ( (key->key()==Qt::Key_Enter) || (key->key()==Qt::Key_Return) ) {
            //Enter or return was pressed

            // how do I make this class do stuff in another class

            MainWindow::EnterPressed();
        } else {
            return QObject::eventFilter(obj, event);
        }
        return true;
    } else {
        return QObject::eventFilter(obj, event);
    }
    return false;
}

// Install the keyEnterReciever event filter onto the appropriate widget (which one is that?)
keyEnterReceiver* key = new keyEnterReceiver();
aWidgetInAnotherClass->installEventFilter(key);

// -- Attempt 2 to catch "Enter"/"Return" key ---
