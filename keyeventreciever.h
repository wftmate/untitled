#ifndef KEYEVENTRECIEVER_H
#define KEYEVENTRECIEVER_H
#include <QObject>

// Define event filter class
class keyEnterReceiver : public QObject
{
    Q_OBJECT

protected:
    bool eventFilter(QObject* obj, QEvent* event);
};

#endif // KEYEVENTRECIEVER_H
