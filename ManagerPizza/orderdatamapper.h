#ifndef ORDERDATAMAPPER_H
#define ORDERDATAMAPPER_H

#include <QString>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include "QtSql/QSqlError"
#include <QMessageBox>
#include <QDebug>

class OrderDataMapper
{
public:
    OrderDataMapper();
    bool CreateDBConnection();
    QString FindOrder(QString id);
    //bool InsertOrder(QString ID_courier, QString ID_worker, QString clientName, QString address, QString ingredientName, QString pizzaName, QString summary, QString payment);
    bool InsertOrder(QString ID_courier, QString ID_worker, QString ingredientName, QString pizzaName, QString summary, QString payment);
    QMap<int, QString> SelectOrder();
    QMap<int, QString> SelectOrderByWorker(QString id);
    QString DeleteOrder(QString id);

private:
    QSqlDatabase m_db;
};

#endif // ORDERDATAMAPPER_H
