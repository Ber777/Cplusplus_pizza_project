#include "orderservice.h"

OrderService::OrderService()
{

}

/*bool OrderService::Find(QString str)
{
    m_id = dataMapper.FindCourier(str);
    if(m_id.isEmpty())
    {
        m_isInDataBase = false;
        return m_isInDataBase;
    }
    else
    {
        m_isInDataBase = true;
        return m_isInDataBase;
    }
}*/

/*bool OrderService::SaveInDataBase(QString ID_courier, QString ID_worker, QString clientName, QString address, QString ingredientName, QString pizzaName, QString summary, QString payment)
{
    bool isRightQuery = orderDataMapper.InsertOrder(ID_courier, ID_worker, clientName, address, ingredientName, pizzaName, summary, payment);
    if(isRightQuery)
        return true;
    else
        return false;
}*/

bool OrderService::Find(QString str)
{
    m_id = orderDataMapper.FindOrder(str);
    if(m_id.isEmpty())
    {
        m_isInDataBase = false;
        return m_isInDataBase;
    }
    else
    {
        m_isInDataBase = true;
        return m_isInDataBase;
    }
}

bool OrderService::SaveInDataBase(QString ID_courier, QString ID_worker, QString ingredientName, QString pizzaName, QString summary, QString payment)
{
    bool isRightQuery = orderDataMapper.InsertOrder(ID_courier, ID_worker, ingredientName, pizzaName, summary, payment);
    if(isRightQuery)
        return true;
    else
        return false;
}

QMap<int, QString> OrderService::SeeInfo()
{
    QMap<int, QString> map;
    map = orderDataMapper.SelectOrder();
    return map;
}

bool OrderService::Delete(QString str)
{
    m_id = orderDataMapper.DeleteOrder(str);
    if(m_id.isEmpty())
    {
        m_isInDataBase = false;
        return m_isInDataBase;
    }
    else
    {
        m_isInDataBase = true;
        return m_isInDataBase;
    }
}
