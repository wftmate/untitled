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

private slots: // slots are functions connected to buttons on windows (widgets)
    void EnterPressed();

//// -- Method 1: installEventFilter on Input object -------------------------------
//private:
//    bool eventFilter(QObject *target, QEvent *event) override;

// -- Method 2: Rewrite keyPressEvent() function -----------------------------------
// This overrides the default keyPressEvent implicit in the QObject or whatever
protected:
    void keyPressEvent( /*QObject *target,*/ QKeyEvent *event );
    void keyReleaseEvent(QKeyEvent *event);

// -- Method 3: shortcuts (note yet implemented) -----------------------------------
};
#endif // MAINWINDOW_H
