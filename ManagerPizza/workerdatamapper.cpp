#include "workerdatamapper.h"

WorkerDataMapper::WorkerDataMapper()
{

}

bool WorkerDataMapper::CreateDBConnection()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:\\Qt\\Pizza\\databasePizza.db");
    if (!m_db.open())
    {
        qDebug() << "Cannot open database:" << m_db.lastError();
        return false;
    }

    return true;
}

QString WorkerDataMapper::FindWorker(QString workerName)
{
    CreateDBConnection();
    QSqlQuery query;
    QString idC;

    query.exec("SELECT ID_worker FROM Workers WHERE workername = '"+workerName+"'");

    while(query.next())
    {
        idC = query.value(0).toString();
    }

    m_db.close();

    return idC;
}

QString WorkerDataMapper::GetWorker(Worker& worker)
{
    CreateDBConnection();
    QSqlQuery query;
    QString idW;
    QString name;
    QString sal;
    QString pos;
    QString phone;

    query.exec("SELECT ID_worker, workername, salary, position, phone FROM Workers WHERE passport = '"+worker.GetPassport()+"'");

    while(query.next())
    {
        idW = query.value(0).toString();
        name = query.value(1).toString();
        sal = query.value(2).toString();
        pos = query.value(3).toString();
        phone = query.value(4).toString();
    }

    worker.SetId(idW);
    worker.SetWorkerName(name);
    worker.SetSalary(sal);
    worker.SetPosition(pos);
    worker.SetPhone(phone);

    m_db.close();

    return idW;
}

bool WorkerDataMapper::InsertWorker(QString workerName, QString passport, QString salary, QString position, QString phone)
{
    CreateDBConnection();
    QSqlQuery query;
    bool isAllRight = query.exec("INSERT INTO Workers (workername, passport, salary, position, phone) VALUES ('"+workerName+"', '"+passport+"', '"+salary+"', '"+position+"', '"+phone+"')");
    return isAllRight;
}

QMap<int, QString> WorkerDataMapper::SelectWorker()
{
    CreateDBConnection();
    QSqlQuery query;
    QMap<int, QString> map;
    int i=0;
    query.exec("SELECT ID_worker, passport, phone, salary, position, workername FROM Workers");
    while (query.next())
    {
        QString idw = query.value(0).toString();
        QString pass = query.value(1).toString();
        QString phone = query.value(2).toString();
        QString sal = query.value(3).toString();
        QString pos = query.value(4).toString();
        QString name = query.value(5).toString();
        QString str = ""+idw+"                       "+pass+"               "+phone+"             "+sal+"        "+pos+"                         "+name+"        \n";
        map.insert(i,str);
        i++;
    }

    m_db.close();
    return map;
}

QString WorkerDataMapper::DeleteWorker(QString workerName)
{
    CreateDBConnection();
    QSqlQuery query, query1;
    QString idC;

    query1.exec("SELECT ID_worker FROM Workers WHERE workername = '"+workerName+"'");
    while(query1.next())
    {
        idC = query1.value(0).toString();
    }

    query.exec("DELETE FROM Workers WHERE workername = '"+workerName+"'");

    m_db.close();

    return idC;
}

QStringList WorkerDataMapper::FormQueryToSearchWorkerInTableOrders(Worker worker)
{
    CreateDBConnection();
    QSqlQuery query;
    query.exec("SELECT Workers.ID_worker FROM Orders, Workers WHERE Orders.ID_worker='"+worker.GetId()+"' AND Orders.ID_worker=Workers.ID_worker");
    QStringList listOfWorkers;
    //unsigned int i = 0; // сечт для заполнения списка артистов
    while (query.next())
    {
         listOfWorkers << query.value(0).toString();
    }
    return listOfWorkers;
}

QStringList WorkerDataMapper::FormQueryToSearchWorkerInfo(QString id)
{
    QSqlQuery query;
    query.exec("SELECT distinct workername, salary, position, phone FROM Workers WHERE ID_worker='"+id+"'");
    QStringList listOfWorkers;

    while (query.next())
    {
         listOfWorkers << query.value(0).toString();
         listOfWorkers << query.value(1).toString();
         listOfWorkers << query.value(2).toString();
         listOfWorkers << query.value(3).toString();
    }

    return listOfWorkers;
}
QStringList WorkerDataMapper::FormQueryToSearchOrdersByWorker(Worker worker)
{
    QSqlQuery query1;
    QStringList listOfOrders;
    query1.exec("SELECT distinct ID_order FROM Orders WHERE ID_worker='"+worker.GetId()+"'");
    while (query1.next())
    {
        listOfOrders << query1.value(0).toString();
    }

    return listOfOrders;
}
