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

    connect_me("local", 8080);

    return app.exec();
}
