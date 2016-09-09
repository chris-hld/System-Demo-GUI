#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    window.resize(600, 300);
    window.setWindowTitle("Reproduction Systems");
    window.show();

    window.show();

    return app.exec();
}
