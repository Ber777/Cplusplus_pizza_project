#ifndef PIZZA_H
#define PIZZA_H
#include <QString>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include "QtSql/QSqlError"

class Pizza
{
public:
    Pizza();
    void SetPizzaName(QString pizzaName);
    QString GetPizzaName();
    QString GetId();
    QSqlQuery GetQueryPizzaName();
    QSqlQuery GetQueryPizzaSummary(QString str);
    int GetQueryPizzaSummary1(QString str);

private:
    QString m_pizzaName;
    QString m_id;
    QSqlDatabase m_db;
};

#endif // PIZZA_H
