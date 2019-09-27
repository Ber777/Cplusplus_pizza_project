#ifndef DATAMAPPER_H
#define DATAMAPPER_H

#include <QString>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include "QtSql/QSqlError"
#include <QMessageBox>
#include <QDebug>

class DataMapper
{
public:
    DataMapper();

    //QString FindCourier(QString courierName);
    //QString FindWorker(QString workerName);
    //QString FindClient(QString clientName);
    //QString FindOrder();

    //bool CreateDBConnection();
    //bool InsertCourier(QString courierName, QString passport, QString salary, QString phone, QString transport);
    //bool InsertWorker(QString workerName, QString passport, QString salary, QString position, QString phone);
    //bool InsertIngredient(QString ingredientName, QString summary);
    //bool InsertPizza(QString pizzaName, QString summary);
    //bool InsertOrder(QString ID_courier, QString ID_worker, QString clientName, QString address, QString ingredientName, QString pizzaName, QString summary, QString payment);

    //int GetIngSum1(QString ingredientName);
    //int GetPizzaSum1(QString pizzaName);

    //QSqlQuery GetQueryIngName();
    //QSqlQuery GetQueryPizName();
    //QSqlQuery GetIngSum(QString ingredientName);
    //QSqlQuery GetPizzaSum(QString pizzaName);

    //QMap<int, QString> SelectCourier();
    //QMap<int, QString> SelectWorker();
    //QMap<int, QString> SelectIngredient();
    //QMap<int, QString> SelectPizza();
    //QMap<int, QString> SelectClient();
    //QMap<int, QString> SelectOrder();

    //QString DeleteCourier(QString courierName);
    //QString DeleteWorker(QString workerName);
    //QString DeleteClient(QString clientName);
    //QString DeleteOrder(QString ID_courier, QString ID_worker, QString clientName, QString address, QString ingredientName, QString pizzaName, QString summary, QString payment);

//private:
//    QSqlDatabase m_db;

};

#endif // DATAMAPPER_H
