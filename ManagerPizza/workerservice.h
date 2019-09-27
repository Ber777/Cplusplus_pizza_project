#ifndef WORKERSERVICE_H
#define WORKERSERVICE_H

#include <workerdatamapper.h>
#include <worker.h>

class WorkerService
{
public:
    WorkerService();
    bool Find(QString str);
    bool SavaInDataBase(QString name, QString passport, QString salary, QString phone, QString position);
    QMap<int, QString> SeeInfo();
    QStringList WorkersInOrders(Worker worker);
    QStringList WorkersOrdersWorkers(Worker worker);
    QStringList WorkersInfo(QString id);
    QString GetWorker(Worker& worker);
    bool Delete(QString str);

private:
    WorkerDataMapper workerDataMapper;
    Worker worker;
    QString m_id;
    bool m_isInDataBase;
};

#endif // WORKERSERVICE_H
