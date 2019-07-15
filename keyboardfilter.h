#ifndef KEYBOARDFILTER_H
#define KEYBOARDFILTER_H

#include <QApplication>
#include <QLineEdit>
#include <QKeyEvent>

class KeyboardFilter : public QObject
{
public:
    KeyboardFilter( QObject *parent = nullptr ) : QObject( parent ) {}

//protected:
public:
    bool eventFilter( QObject *target, QEvent *event );
};

#endif // KEYBOARDFILTER_H
