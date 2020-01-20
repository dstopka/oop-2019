#include "socket.h"

Socket::Socket(QTcpSocket* _socket)
{
    socket = _socket;
    connect(socket, SIGNAL(readyRead()), this, SLOT(receivedData()));
}

void Socket::receivedData()
{
    QTextStream stream(socket);
    QString data;
    data = stream.readAll();
    stream << data.toUpper();
}
