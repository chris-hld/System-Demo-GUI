#include <thread>         // std::thread
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connect_tcp_client.h"
#include "parameter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create and position the button
    load_button = new QPushButton("Load", this);
    load_button->move(210, 20);
    play_button = new QPushButton("Play", this);
    play_button->move(190, 75);
    play_button->setStyleSheet("background-color: green");
    stop_button = new QPushButton("Stop", this);
    stop_button->move(290, 75);
    stop_button->setStyleSheet("background-color: red");

    stereo_button = new QPushButton("Stereo", this);
    stereo_button->resize(80, 80);
    stereo_button->move(20, 160);
    surround_button = new QPushButton("Surround", this);
    surround_button->resize(80, 80);
    surround_button->move(250, 160);
    wfs_button = new QPushButton("WFS", this);
    wfs_button->resize(80, 80);
    wfs_button->move(500, 160);

    EXIT = new QPushButton("EXIT", this);
    EXIT->move(10, 20);
    connectHost_button = new QPushButton("Connect", this);
    connectHost_button->setCheckable( true );
    connectHost_button->move(110, 20);


    // Do the connection
    connect(load_button, SIGNAL (clicked()),
            this,  SLOT (slotLoadClicked()));
    connect(play_button, SIGNAL (clicked()),
            this,  SLOT (slotPlayClicked()));
    connect(stop_button, SIGNAL (clicked()),
            this,  SLOT (slotStopClicked()));

    connect(EXIT, SIGNAL (clicked()),
            this,  SLOT (slotConnectExit()));
    connect(connectHost_button, SIGNAL (clicked(bool)),
            this, SLOT (slotConnectClicked(bool)));

    connect(stereo_button, SIGNAL (released()),
            this,  SLOT (slotSystemAClicked()));
    connect(surround_button, SIGNAL (released()),
            this,  SLOT (slotSystemBClicked()));
    connect(wfs_button, SIGNAL (released()),
            this,  SLOT (slotSystemCClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::slotConnectClicked(bool checked)
{
    extern Parameter global_socket;
    std::thread connectButtonThread (connect_viaButton,
       global_socket.getHostname(), global_socket.getPortno());
      if (checked) {
        connectHost_button->setText("Connected");
        //connect_viaButton();
        connectButtonThread.detach();  // don't wait for it
      } else {
        connectHost_button->setText("Empty");
      }
}

void MainWindow::slotLoadClicked()
{
    send_TCP("list stereo.wav surround.wav wfs.wav;");
}

void MainWindow::slotPlayClicked()
{
    MainWindow::slotLoadClicked();
    send_TCP("play;");
}

void MainWindow::slotStopClicked()
{
    send_TCP("stop;");
}

void MainWindow::slotConnectExit(){
    close_connection();
    connectHost_button->setText("Empty");
    std::terminate();
};

void MainWindow::slotSystemAClicked()
{
    send_TCP("A;");
}

void MainWindow::slotSystemBClicked()
{
  send_TCP("B;");
}

void MainWindow::slotSystemCClicked()
{
    send_TCP("C;");
}
