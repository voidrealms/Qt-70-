#include "mytask.h"

MyTask::MyTask()
{
}

void MyTask::run()
{
    //time consumer

    qDebug() << "Task Start";

    int iNumber = 0;
    for(int i = 0; i < 1000; i++)
    {
        iNumber += i;
    }

    qDebug() << "Task Done";

    emit Result(iNumber);
}
