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

//private:
public:
    Ui::MainWindow *ui;

// handles clicking the enter button with the mouse
//private slots:
public slots:
    void EnterPressed();

// handles when the enter/return key is pressed
public:
    static void EnterKeyPressed();

};
#endif // MAINWINDOW_H
