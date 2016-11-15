#include "mainwindow.h"
#include <QApplication>
#include "connectTCPclient.cpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    window.resize(600, 300);
    window.setWindowTitle("Reproduction Systems");
    window.show();

    window.show();

    if (argc > 1 && argv[1] == std::string("-tcp")) {
      char* hostname = argv[2];
      int portno = atoi(argv[3]);
      connect_me(hostname, portno);
    }

    return app.exec();
}
