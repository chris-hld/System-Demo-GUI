#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>


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
    QPushButton *connectHost;

private slots:
    void slotButtonClicked(bool checked);
};

#endif // MAINWINDOW_H
