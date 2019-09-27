#ifndef WORKERDATAMAPPER_H
#define WORKERDATAMAPPER_H

#include <QString>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include "QtSql/QSqlError"
#include <QMessageBox>
#include <QDebug>
#include <Worker.h>

class WorkerDataMapper
{
public:
    WorkerDataMapper();
    bool CreateDBConnection();
    QString FindWorker(QString workerName);
    QString GetWorker(Worker& worker);
    bool InsertWorker(QString workerName, QString passport, QString salary, QString position, QString phone);
    QMap<int, QString> SelectWorker();
    QString DeleteWorker(QString workerName);
    QStringList FormQueryToSearchWorkerInTableOrders(Worker worker);
    QStringList FormQueryToSearchWorkerInfo(QString id);
    QStringList FormQueryToSearchOrdersByWorker(Worker worker);

private:
    QSqlDatabase m_db;
};

#endif // WORKERDATAMAPPER_H
