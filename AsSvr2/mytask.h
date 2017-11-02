#ifndef MYTASK_H
#define MYTASK_H

#include <QDebug>
#include <QObject>
#include <QRunnable>

class MyTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    MyTask();

signals:
    void Result(int Number);

protected:
    void run();
};

#endif // MYTASK_H
