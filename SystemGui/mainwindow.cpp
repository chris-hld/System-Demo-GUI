#include <thread>         // std::thread

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connect_tcp_client.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create and position the button
    stereo_button = new QPushButton("Stereo", this);
    stereo_button->resize(80, 80);
    stereo_button->move(20, 200);
    surround_button = new QPushButton("Surround", this);
    surround_button->resize(80, 80);
    surround_button->move(250, 200);
    wfs_button = new QPushButton("WFS", this);
    wfs_button->resize(80, 80);
    wfs_button->move(500, 200);

    EXIT = new QPushButton("EXIT", this);
    EXIT->move(10, 10);
    connectHost_button = new QPushButton("connect", this);
    connectHost_button->setCheckable( true );
    connectHost_button->move(100, 10);


    // Do the connection
    connect(EXIT, SIGNAL (clicked()),
            QApplication::instance(), SLOT (quit()));
    connect(connectHost_button, SIGNAL (clicked(bool)),
            this, SLOT (slotButtonClicked(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void connect_viaButton(const char* hostname, int portno)
{
    connect_me(hostname, portno);
}

void MainWindow::slotButtonClicked(bool checked)
{
    if (checked) {
      connectHost_button->setText("Connected");
      //connect_viaButton();
      const char* hostname = "localhost";
      int portno = 8080;
      std::thread connectButtonThread (connect_viaButton, hostname, portno);
      connectButtonThread.detach();  // don't wait for it

    } else {
      connectHost_button->setText("Empty");
    }
}
