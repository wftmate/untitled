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

// handles clicking the enter button with the mouse
private slots:
    void EnterPressed();
    bool eventFilter(QObject *target, QEvent *event) override;

// handles when the enter/return key is pressed
// This overrides the default keyPressEvent implicit in the QObject or whatever
//protected:
//    void keyPressEvent( /*QObject *target,*/ QKeyEvent *event );
//    void keyReleaseEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
