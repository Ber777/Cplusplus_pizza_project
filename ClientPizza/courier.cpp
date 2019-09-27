#include "courier.h"

Courier::Courier()
{

}

void Courier::SetCourierName(QString courierName)
{
    m_courierName = courierName;
}

void Courier::SetPhone(QString phone)
{
    m_phone = phone;
}

void Courier::SetPassport(QString passport)
{
    m_passport = passport;
}

void Courier::SetBirthday(QString birthday)
{
    m_birthday = birthday;
}

void Courier::SetTransport(QString transport)
{
    m_transport = transport;
}

QString Courier::GetCourierName()
{
    return m_courierName;
}

QString Courier::GetPassport()
{
    return m_passport;
}

QString Courier::GetBirthday()
{
    return m_birthday;
}

QString Courier::GetPhone()
{
    return m_phone;
}

QString Courier::GetTransport()
{
    return m_transport;
}

QString Courier::GetId()
{
    return m_id;
}

/*bool Courier::Find()
{
   m_id = FormQueryToSearchCourier(m_courierName, m_passport, m_birthday, m_phone, m_transport);
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

QString Courier::FormQueryToSearchCourier(QString courierName, QString passport, QString birthday, QString phone, QString transport)
{
    QSqlQuery query;
    query.exec("SELECT ID_courier FROM Clients WHERE couriername='"+courierName+"' AND passport='"+passport+"' AND birthday='"+birthday+"' AND phone='"+phone+"' AND transport='"+transport+"'");
    QString idCourier;
    while (query.next())
    {
         idCourier = query.value(0).toString();
    }
    return idCourier;
}

bool Courier::FormQueryToInsertCourierValue(QString courierName, QString passport, QString birthday, QString phone, QString transport)
{
     QSqlQuery query;
     bool isRightQuery = query.exec("INSERT INTO Courier (couriername, passport, birthday, phone, transport) VALUES('" + courierName + "','" + passport + "', '" + birthday + "', '" + phone + "', '" + transport + "')");
     return isRightQuery;
}

QStringList Courier::FormQueryToSearchCourierInfo(QString idCourier)
{
    QSqlQuery query;
    query.exec("SELECT couriername, passport, birthday, phone, transport FROM Courier WHERE ID_courier='"+idCourier+"'");
    QStringList listOfCourierInfo;

    while (query.next())
    {
         listOfCourierInfo << query.value(0).toString();
         listOfCourierInfo << query.value(1).toString();
         listOfCourierInfo << query.value(2).toString();
         listOfCourierInfo << query.value(3).toString();
         listOfCourierInfo << query.value(4).toString();
    }
    return listOfCourierInfo;
}

bool Courier::GetStatusInDataBase()
{
    return m_isInDataBase;
}

void Courier::SetStatusInDataBase(bool isInDataBase)
{
    m_isInDataBase = isInDataBase;
}

bool Courier::SaveInDataBase()
{
    // добавила данные по артитисту в табл -курьер-
    bool isRightQuery = FormQueryToInsertCourierValue(m_courierName, m_passport, m_birthday, m_phone, m_transport);
    // если запрос выполнился корректно(узнаю присвоенный id добавленному артисту
    if(isRightQuery)
    {
        // узнать id добаленного курьера(необходимо для формирования талицы -гонорар-)
        m_id = FormQueryToSearchCourier(m_courierName, m_passport, m_birthday, m_phone, m_transport);
        // добавление прошло корректно
        return true;
    }
    else
    {
        return false;
    }
}
void Courier::UnInitialazeVales()
{
     m_courierName = "";
     m_birthday = "";
     m_passport = "";
     m_phone = "";
     m_transport = "";
     m_id = "";
     m_isInDataBase = false;
}*/
