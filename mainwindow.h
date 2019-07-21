#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QKeyEvent>

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
    void BackspacePressed();

// -- Method 1 --------------------------------------------------------------------
private slots:
    void EnterPressed();
    bool eventFilter(QObject *target, QEvent *event) override;

//// -- Method 2 --------------------------------------------------------------------
//// This overrides the default keyPressEvent implicit in the QObject or whatever
//protected:
//    void keyPressEvent( /*QObject *target,*/ QKeyEvent *event );
//    void keyReleaseEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
