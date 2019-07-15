#include "keyeventreciever.h"
#include <QKeyEvent>

bool enterPressed = false;

// Define what the eventFilter function beloning to the keyEnterReciever class does
bool keyEnterReceiver::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type()==QEvent::KeyPress) {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        if ( (key->key()==Qt::Key_Enter) || (key->key()==Qt::Key_Return) ) {
            //Enter or return was pressed

            // how do I make this class do stuff in another class
            enterPressed = true;
            //MainWindow::EnterPressed();
        } else {
            return QObject::eventFilter(obj, event);
        }
        return true;
    } else {
        return QObject::eventFilter(obj, event);
    }
    //return false;
}

// Install the keyEnterReciever event filter onto the appropriate widget (which one is that?)
keyEnterReceiver* key = new keyEnterReceiver();
aWidgetInAnotherClass->installEventFilter(key);

MainWindow->installEventFilter(key);
