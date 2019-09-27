#include "pizza.h"

Pizza::Pizza()
{

}

void Pizza::SetPizzaName(QString pizzaName)
{
    m_pizzaName = pizzaName;
}

QString Pizza::GetPizzaName()
{
    return m_pizzaName;
}

QString Pizza::GetId()
{
    return m_id;
}

QSqlQuery Pizza::GetQueryPizzaName()
{
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT pizzaname || ' ' || '+(' || summary || 'р.)' FROM Pizza");
    qry->exec();
    qry->first();
    m_db.close();
    return *qry;
}

QSqlQuery Pizza::GetQueryPizzaSummary(QString str)
{
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT summary FROM Pizza WHERE pizzaname = '"+str+"'");
    qry->exec();
    qry->first();
    m_db.close();
    return *qry;
}

int Pizza::GetQueryPizzaSummary1(QString str)
{
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT summary FROM Pizza WHERE pizzaname = '"+str+"'");
    qry->exec();
    qry->first();
    m_db.close();
    return qry->value(0).toInt();
}
