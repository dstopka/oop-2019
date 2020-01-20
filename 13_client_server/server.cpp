#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    server->listen(QHostAddress::Any, 8000);
    connect(server, SIGNAL(newConnection()), this, SLOT(makeConnection()));
}

void Server::makeConnection()
{
    new Socket(server->nextPendingConnection());
}
