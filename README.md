# System-Demo-GUI
Switch between three systems via TCP/IP send.

Build
-----
Run `qmake`, `make` [, `make clean`].



![GUI](/images/screenshot.png)



Use
-----
>`./SystemGui`

only starts the GUI, without starting the TCP client.

Clicking the button `connect` starts the client and establishes TCP connection, by default to `localhost:8445`.

The -tcp flag allows to specify host and port, e.g.:
>./SystemGui -tcp theHost 8060

Starts the GUI and connects to `theHost` port `8060` via TCP.
`EXIT` closes socket and terminates.

The remaining buttons send a TCP message when clicked, e.g.:
The button `Stereo` sends an "A", `Surround` a "B" and `WFS` a "C".
