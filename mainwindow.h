#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

// handles clicking the enter button with the mouse
//private slots:
public slots:
    void EnterPressed();

// supposed to handle key presses. doesn't actually work
//protected:
public:
    void KeyPressEvent(QKeyEvent *event);
    void KeyReleaseEvent(QKeyEvent *event);
    bool EventFilter(QEvent *event);
};

#endif // MAINWINDOW_H
