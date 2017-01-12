#include <QApplication>
#include "mainwindow.h"
#include "parameter.h"

// Globale parameter class
Parameter global_socket;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;

    window.resize(600, 300);
    window.setWindowTitle("Reproduction Systems");
    window.show();

    window.show();

   if (argc > 1 && argv[1] == std::string("-tcp")) {
     const char* hostname = argv[2];
     const int portno = atoi(argv[3]);
     global_socket.setHostname(hostname);
     global_socket.setPortno(portno);
   } else{
     global_socket.setHostname("localhost");
     global_socket.setPortno(8080);
   }

return app.exec();
}
