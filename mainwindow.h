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
    void KeyPressEvent(QKeyEvent * event);
    void KeyReleaseEvent(QKeyEvent * event);

private slots:
    void EnterPressed();

//protected:
//    void KeyPressEvent(QKeyEvent * event);
//    void KeyReleaseEvent(QKeyEvent * event);
};

#endif // MAINWINDOW_H
