#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
}

void MyServer::StartServer()
{
    if(listen(QHostAddress::Any,1234))
    {
        qDebug() << "started";
    }
    else
    {
        qDebug() << "not started!";
    }
}

void MyServer::incomingConnection(int handle)
{
    MyClient *client = new MyClient(this);
    client->SetSocket(handle);
}
