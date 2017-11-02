#include "myclient.h"

MyClient::MyClient(QObject *parent) :
    QObject(parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(15);
}

void MyClient::SetSocket(int Descriptor)
{
    socket = new QTcpSocket(this);

    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));

    socket->setSocketDescriptor(Descriptor);

    qDebug() << "client connected";

}

void MyClient::connected()
{
    qDebug() << "client connected event";
}

void MyClient::disconnected()
{
    qDebug() << "client disconnected";
}

void MyClient::readyRead()
{
    qDebug() << socket->readAll();

    //Time Consumer
    MyTask *mytask = new MyTask();
    mytask->setAutoDelete(true);
    connect(mytask,SIGNAL(Result(int)),SLOT(TaskResult(int)), Qt::QueuedConnection);
    QThreadPool::globalInstance()->start(mytask);
}

void MyClient::TaskResult(int Number)
{
    //right here

    QByteArray Buffer;
    Buffer.append("\r\nTask Result = ");
    Buffer.append(QString::number(Number));

    socket->write(Buffer);
}
