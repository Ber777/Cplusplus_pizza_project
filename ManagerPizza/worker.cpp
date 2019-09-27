#include "worker.h"

Worker::Worker()
{

}

void Worker::SetWorkerName(QString workerName)
{
    m_workerName = workerName;
}

void Worker::SetPhone(QString phone)
{
    m_phone = phone;
}

void Worker::SetPassport(QString passport)
{
    m_passport = passport;
}

void Worker::SetId(QString id)
{
    m_id = id;
}

/*void Worker::SetBirthday(QString birthday)
{
    m_birthday = birthday;
}*/

void Worker::SetSalary(QString salary)
{
    m_salary = salary;
}

void Worker::SetPosition(QString position)
{
    m_position = position;
}

QString Worker::GetWorkerName()
{
    return m_workerName;
}

QString Worker::GetPassport()
{
    return m_passport;
}

/*QString Worker::GetBirthday()
{
    return m_birthday;
}*/

QString Worker::GetPhone()
{
    return m_phone;
}

QString Worker::GetPosition()
{
    return m_position;
}

QString Worker::GetSalary()
{
    return m_salary;
}

QString Worker::GetId()
{
    return m_id;
}

bool Worker::GetStatusInDataBase()
{
    return m_isInDataBase;
}

void Worker::SetStatusInDataBase(bool isInDataBase)
{
    m_isInDataBase = isInDataBase;
}
