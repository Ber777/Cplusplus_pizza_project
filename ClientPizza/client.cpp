#include "client.h"
#include"QDebug"
#include"QSqlError"

Client::Client()
{

}

void Client::SetClientName(QString clientName)
{
    m_clientName = clientName;
}

void Client::SetPhone(QString phone)
{
    m_phone = phone;
}

void Client::SetAdress(QString address)
{
    m_address = address;
}

/*void Client::SetLogin(QString login)
{
    m_login = login;
}

void Client::SetPassword(QString password)
{
    m_password = password;
}*/

/*bool Client::Find()
{
    // вызов функции из DM на поиск артиста в базе
   m_id = FormQueryToSearchClient(m_clientName);
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

bool Client::GetStatusInDataBase()
{
    return m_isInDataBase;
}

void Client::SetStatusInDataBase(bool isInDataBase)
{
    m_isInDataBase = isInDataBase;
}*/

QString Client::GetId()
{
    return m_id;
}

bool Client::CreateDBConnection()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:\\Qt\\databasePizza.db");
    if (!m_db.open())
    {
        qDebug() << "Cannot open database:" << m_db.lastError();
        return false;
    }

    qDebug() << "USPEX";
    return true;
}

QString Client::SelectClientName(QString name)
{
    QSqlQuery query;
    query.exec("SELECT clientname FROM Clients WHERE ID_client = 1");
    query.first();
    name = query.value(0).toString();

    return name;
}

QString Client::SelectClientAddress(QString address)
{
    QSqlQuery query;
    query.exec("SELECT address FROM Clients WHERE ID_client = 1");
    query.first();
    address = query.value(0).toString();

    return address;
}

bool Client::UpdateClientAddress(QString address)
{
    QSqlQuery test;
    test.first();
    bool a = test.exec("UPDATE Clients SET address = '"+address+"' WHERE ID_client = 1");
    m_db.close();
    return a;
}
/*bool Client::SaveInDataBase()
{
    // добавила данные по артитисту в табл -артист-
    bool isRightQuery = FormQueryToInsertClientValue(m_clientName, m_address);
    // если запрос выполнился корректно(узнаю присвоенный id добавленному артисту
    if(isRightQuery)
    {
        // узнать id добаленного артиста(необходимо для формирования талицы -гонорар-)
        m_id = FormQueryToSearchClient(m_clientName);
        // добавление прошло корректно
        return true;
    }
    else
    {
        return false;
    }
}*/
