#include "pizzaservice.h"

PizzaService::PizzaService()
{

}

QSqlQuery PizzaService::SelectPizName()
{
    QSqlQuery *qry = new QSqlQuery(m_db);
    *qry = pizzaDataMapper.GetQueryPizName();
    return *qry;
}

QSqlQuery PizzaService::SelectPizSummary(QString str)
{
    QSqlQuery *qry = new QSqlQuery(m_db);
    *qry = pizzaDataMapper.GetPizzaSum(str);
    return *qry;
}

int PizzaService::SelectPizSummary1(QString str)
{
    int summary = pizzaDataMapper.GetPizzaSum1(str);
    return summary;
}

QMap<int, QString> PizzaService::SeeInfo()
{
    QMap<int, QString> map;
    map = pizzaDataMapper.SelectPizza();
    return map;
}

bool PizzaService::SaveInDataBase(QString name, QString summary)
{
    bool isRightQuery = pizzaDataMapper.InsertPizza(name, summary);
    if(isRightQuery)
        return true;
    else
        return false;
}
