#include "keyboardfilter.h"

bool KeyboardFilter::eventFilter( QObject *dist, QEvent *event )
{
    if( event->type() == QEvent::KeyPress )
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>( event );

        if(keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter){
            return true;
        }

//    if( QString("1234567890").indexOf( keyEvent->text() ) != -1 )
//        return true;
//    }
    }
    return false;
}
