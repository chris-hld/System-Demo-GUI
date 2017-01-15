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
    stereo_button = new QPushButton("Stereo", this);
    stereo_button->resize(80, 80);
    stereo_button->move(20, 150);
    surround_button = new QPushButton("Surround", this);
    surround_button->resize(80, 80);
    surround_button->move(250, 150);
    wfs_button = new QPushButton("WFS", this);
    wfs_button->resize(80, 80);
    wfs_button->move(500, 150);

    EXIT = new QPushButton("EXIT", this);
    EXIT->move(10, 10);
    connectHost_button = new QPushButton("connect", this);
    connectHost_button->setCheckable( true );
    connectHost_button->move(100, 10);


    // Do the connection
    connect(EXIT, SIGNAL (clicked()),
            this,  SLOT (slotConnectExit()));
    connect(connectHost_button, SIGNAL (clicked(bool)),
            this, SLOT (slotConnectClicked(bool)));

    connect(stereo_button, SIGNAL (clicked()),
            this,  SLOT (slotSystemAClicked()));
    connect(surround_button, SIGNAL (clicked()),
            this,  SLOT (slotSystemBClicked()));
    connect(wfs_button, SIGNAL (clicked()),
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

void MainWindow::slotConnectExit(){
  close_connection();
  connectHost_button->setText("Empty");
  std::terminate();
};
void MainWindow::slotSystemAClicked()
{
  QTextStream out(stdout);
  out << "A" << endl;
  send_TCP("A \n");

}

void MainWindow::slotSystemBClicked()
{
  QTextStream out(stdout);
  out << "B" << endl;
  send_TCP("B \n");
}

void MainWindow::slotSystemCClicked()
{
  QTextStream out(stdout);
  out << "C" << endl;
  send_TCP("C \n");
}
