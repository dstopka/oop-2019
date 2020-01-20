#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Socket : public QObject
{
    Q_OBJECT
public:
    explicit Socket(QTcpSocket* _socket);

signals:

public slots:
    void receivedData();
private:
    QTcpSocket* socket;
};

#endif // CLIENT_H
