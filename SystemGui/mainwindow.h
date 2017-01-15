#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextStream>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QPushButton *stereo_button;
    QPushButton *surround_button;
    QPushButton *wfs_button;
    QPushButton *EXIT;
    QPushButton *connectHost_button;

private slots:
    void slotConnectClicked(bool checked);
    void slotConnectExit();
    void slotSystemAClicked();
    void slotSystemBClicked();
    void slotSystemCClicked();

};

#endif // MAINWINDOW_H
