#include "pizza.h"

Pizza::Pizza()
{

}

void Pizza::SetPizzaName(QString pizzaName)
{
    m_pizzaName = pizzaName;
}
void Pizza::SetPizzaSum(QString summary)
{
    m_summary = summary;
}

QString Pizza::GetPizzaName()
{
    return m_pizzaName;
}

QString Pizza::GetId()
{
    return m_id;
}

QString Pizza::GetPizzaSum()
{
    return m_summary;
}

