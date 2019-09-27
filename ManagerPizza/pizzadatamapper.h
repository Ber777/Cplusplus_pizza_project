#ifndef PIZZADATAMAPPER_H
#define PIZZADATAMAPPER_H

#include <QString>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include "QtSql/QSqlError"
#include <QMessageBox>
#include <QDebug>

class PizzaDataMapper
{
public:
    PizzaDataMapper();
    bool CreateDBConnection();
    bool InsertPizza(QString pizzaName, QString summary);
    int GetPizzaSum1(QString pizzaName);
    QSqlQuery GetQueryPizName();
    QSqlQuery GetPizzaSum(QString pizzaName);
    QMap<int, QString> SelectPizza();

private:
    QSqlDatabase m_db;
};

#endif // PIZZADATAMAPPER_H
