#include "courierservice.h"

CourierService::CourierService()
{

}

bool CourierService::Find(QString str)
{
    m_id = courierDataMapper.FindCourier(str);
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

/*bool CourierService::SaveInDataBase(QString name, QString passport, QString salary, QString phone, QString transport)
{
    bool isRightQuery = courierDataMapper.InsertCourier(name, passport, salary, phone, transport);
    if(isRightQuery)
        return true;
    else
        return false;
}*/

bool CourierService::SaveInDataBase(Courier &courier)
{
    bool isRightQuery = courierDataMapper.InsertCourier(courier.GetCourierName(), courier.GetPassport(), courier.GetCourierSalary(), courier.GetPhone(), courier.GetTransport());
    if(isRightQuery)
        return true;
    else
        return false;
}

QMap<int, QString> CourierService::SeeInfo()
{
    QMap<int, QString> map;
    map = courierDataMapper.SelectCourier();
    return map;
}

bool CourierService::Delete(QString str)
{
    m_id = courierDataMapper.DeleteCourier(str);
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

/*void CourierService::Update(QString name)
{

}*/
