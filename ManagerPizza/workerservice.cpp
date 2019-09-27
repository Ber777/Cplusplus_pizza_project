#include "workerservice.h"

WorkerService::WorkerService()
{

}

bool WorkerService::Find(QString str)
{
    m_id = workerDataMapper.FindWorker(str);
    if(m_id.isEmpty())
    {
        m_isInDataBase = false;
        return m_isInDataBase;
    }
    else
    {
        m_isInDataBase = true;
        return m_isInDataBase;
    }
}

bool WorkerService::SavaInDataBase(QString name, QString passport, QString salary, QString phone, QString position)
{
    bool isRightQuery = workerDataMapper.InsertWorker(name, passport, salary, phone, position);
    if(isRightQuery)
        return true;
    else
        return false;
}

QMap<int, QString> WorkerService::SeeInfo()
{
    QMap<int, QString> map;
    map = workerDataMapper.SelectWorker();
    return map;
}

bool WorkerService::Delete(QString str)
{
    m_id = workerDataMapper.DeleteWorker(str);
    if(m_id.isEmpty())
    {
        m_isInDataBase = false;
        return m_isInDataBase;
    }
    else
    {
        m_isInDataBase = true;
        return m_isInDataBase;
    }
}

QStringList WorkerService::WorkersInOrders(Worker worker)
{
    QStringList ListOfWorkersInOrders;
    ListOfWorkersInOrders = workerDataMapper.FormQueryToSearchWorkerInTableOrders(worker);
    return ListOfWorkersInOrders;
}

QStringList WorkerService::WorkersInfo(QString id)
{
    QStringList ListOfWorkersInOrders;
    ListOfWorkersInOrders = workerDataMapper.FormQueryToSearchWorkerInfo(id);
    return ListOfWorkersInOrders;
}

QStringList WorkerService::WorkersOrdersWorkers(Worker worker)
{
    QStringList ListOfWorkersInOrders;
    ListOfWorkersInOrders = workerDataMapper.FormQueryToSearchOrdersByWorker(worker);
    return ListOfWorkersInOrders;
}

QString WorkerService::GetWorker(Worker &worker)
{
     QString idW = workerDataMapper.GetWorker(worker);
     return idW;
}

