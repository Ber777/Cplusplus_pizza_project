#ifndef PIZZA_H
#define PIZZA_H

#include <QString>

class Pizza
{
public:
    Pizza();
    void SetPizzaName(QString pizzaName);
    void SetPizzaSum(QString summary);
    QString GetPizzaName();
    QString GetId();
    QString GetPizzaSum();

private:
    QString m_pizzaName;
    QString m_summary;
    QString m_id;
};

#endif // PIZZA_H
