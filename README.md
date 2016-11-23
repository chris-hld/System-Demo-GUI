# System-Demo-GUI
Switch between three systems via TCP/IP send.

Building:
Run `qmake`, `make`, `make clean`.

Usage:
`./SystemGui`
only starts the GUI, without starting the TCP client.

Clicking on button `connect` establishes TCP connection to localhost port 8080.

Currently not working:
`./SystemGui -tcp localhost 8080`
Starts the GUI and connects to localhost port 8080 via TCP.
