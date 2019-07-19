#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H


class MainWindow2
{
public:
    MainWindow2();

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

#endif // MAINWINDOW2_H
