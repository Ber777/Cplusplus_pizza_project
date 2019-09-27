#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include <pizzadatamapper.h>
#include <pizza.h>

class PizzaService
{
public:
    PizzaService();
    QSqlQuery SelectPizName();
    QSqlQuery SelectPizSummary(QString str);
    int SelectPizSummary1(QString str);
    QMap<int, QString> SeeInfo();
    bool SaveInDataBase(QString name, QString summary);

private:
    PizzaDataMapper pizzaDataMapper;
    int m_sum;
    QString m_id;
    QString m_ingredientName;
    QSqlDatabase m_db;
};

#endif // PIZZASERVICE_H
