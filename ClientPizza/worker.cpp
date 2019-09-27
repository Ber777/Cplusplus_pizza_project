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

void Worker::SetBirthday(QString birthday)
{
    m_birthday = birthday;
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

QString Worker::GetBirthday()
{
    return m_birthday;
}

QString Worker::GetPhone()
{
    return m_phone;
}

QString Worker::GetPosition()
{
    return m_position;
}

QString Worker::GetId()
{
    return m_id;
}

/*bool Worker::Find()
{
   m_id = FormQueryToSearchWorker(m_workerName, m_passport, m_birthday, m_phone, m_position);
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

QString Worker::FormQueryToSearchWorker(QString workerName, QString passport, QString birthday, QString phone, QString position)
{
    QSqlQuery query;
    query.exec("SELECT ID_courier FROM Clients WHERE workername='"+workerName+"' AND passport='"+passport+"' AND birthday='"+birthday+"' AND phone='"+phone+"' AND transport='"+position+"'");
    QString idWorker;
    while (query.next())
    {
         idWorker = query.value(0).toString();
    }
    return idWorker;
}

bool Worker::FormQueryToInsertWorkerValue(QString workerName, QString passport, QString birthday, QString phone, QString position)
{
     QSqlQuery query;
     bool isRightQuery = query.exec("INSERT INTO Workers (couriername, passport, birthday, phone, transport) VALUES('" + workerName + "','" + passport + "', '" + birthday + "', '" + phone + "', '" + position + "')");
     return isRightQuery;
}

QStringList Worker::FormQueryToSearchWorkerInfo(QString idWorker)
{
    QSqlQuery query;
    query.exec("SELECT workername, passport, birthday, phone, position FROM Courier WHERE ID_courier='"+idWorker+"'");
    QStringList listOfWorkerInfo;

    while (query.next())
    {
         listOfWorkerInfo << query.value(0).toString();
         listOfWorkerInfo << query.value(1).toString();
         listOfWorkerInfo << query.value(2).toString();
         listOfWorkerInfo << query.value(3).toString();
         listOfWorkerInfo << query.value(4).toString();
    }
    return listOfWorkerInfo;
}

bool Worker::GetStatusInDataBase()
{
    return m_isInDataBase;
}

void Worker::SetStatusInDataBase(bool isInDataBase)
{
    m_isInDataBase = isInDataBase;
}

bool Worker::SaveInDataBase()
{
    // добавила данные по артитисту в табл -курьер-
    bool isRightQuery = FormQueryToInsertWorkerValue(m_workerName, m_passport, m_birthday, m_phone, m_position);
    // если запрос выполнился корректно(узнаю присвоенный id добавленному артисту
    if(isRightQuery)
    {
        // узнать id добаленного курьера(необходимо для формирования талицы -гонорар-)
        m_id = FormQueryToSearchWorker(m_workerName, m_passport, m_birthday, m_phone, m_position);
        // добавление прошло корректно
        return true;
    }
    else
    {
        return false;
    }
}
void Worker::UnInitialazeVales()
{
     m_workerName = "";
     m_birthday = "";
     m_passport = "";
     m_phone = "";
     m_position = "";
     m_id = "";
     m_isInDataBase = false;
}*/
