#include "order.h"

Order::Order()
{

}

void Order::SetSum(int sum)
{
    m_summary = sum;
}

void Order::SetId(QString id)
{
    m_id = id;
}

int Order::GetSum()
{
    return m_summary;
}

QString Order::GetId()
{
    return m_id;
}

/*QString Order::GetClientId()
{
    return client.GetId();
}*/

QString Order::GetIngredientId()
{
    return ingredient.GetId();
}

QString Order::GetCourierId()
{
    return courier.GetId();
}

QString Order::GetPaymentId()
{
    return pay.GetId();
}

QString Order::GetPizzaId()
{
    return pizza.GetId();
}

QString Order::GetWorkerId()
{
    return worker.GetId();
}
