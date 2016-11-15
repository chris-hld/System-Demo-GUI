# System-Demo-GUI
Switch between three systems via TCP/IP send.

Building:
Run 'qmake', 'make', 'make clean'.

Usage:
`./SystemGui`
only starts the GUI, without starting the TCP client.

`./SystemGui -tcp local 8080`
Starts the GUI and connects to local host port 8080 via TCP.
