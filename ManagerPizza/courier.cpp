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

void Courier::SetCourierSalary(QString salary)
{
    m_salary = salary;
}

void Courier::SetPassport(QString passport)
{
    m_passport = passport;
}

/*void Courier::SetBirthday(QString birthday)
{
    m_birthday = birthday;
}*/

void Courier::SetTransport(QString transport)
{
    m_transport = transport;
}

/*QString Courier::GetCourierName()
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
}*/

QString Courier::GetId()
{
    return m_id;
}

QString Courier::GetCourierName()
{
    return m_courierName;
}

QString Courier::GetPassport()
{
    return m_passport;
}

QString Courier::GetCourierSalary()
{
    return m_salary;
}

QString Courier::GetPhone()
{
    return m_phone;
}

QString Courier::GetTransport()
{
    return m_transport;
}
