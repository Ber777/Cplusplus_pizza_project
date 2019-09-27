#include "clientdatamapper.h"

ClientDataMapper::ClientDataMapper()
{

}

/*bool ClientDataMapper::CreateDBConnection()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:\\Qt\\Pizza\\databasePizza.db");
    if (!m_db.open())
    {
        qDebug() << "Cannot open database:" << m_db.lastError();
        return false;
    }

    return true;
}

QString ClientDataMapper::FindClient(QString clientName)
{
    CreateDBConnection();
    QSqlQuery query;
    QString idC;

    query.exec("SELECT ID_client FROM Clients WHERE clientname = '"+clientName+"'");

    while(query.next())
    {
        idC = query.value(0).toString();
    }

    m_db.close();

    return idC;
}

QMap<int, QString> ClientDataMapper::SelectClient()
{
    CreateDBConnection();
    QSqlQuery query;
    QMap<int, QString> map;
    int i=0;
    query.exec("SELECT ID_client, phone, clientname, address FROM Clients");
    while (query.next())
    {
        QString idc = query.value(0).toString();
        QString phone = query.value(1).toString();
        QString name = query.value(2).toString();
        QString address = query.value(3).toString();
        QString str = ""+idc+"                       "+phone+"         "+name+"                  "+address+        "\n";
        map.insert(i,str);
        i++;
    }

    m_db.close();
    return map;
}

QString ClientDataMapper::DeleteClient(QString clientName)
{
    CreateDBConnection();
    QSqlQuery query, query1;
    QString idC;

    query1.exec("SELECT ID_client FROM Clients WHERE clientname = '"+clientName+"'");
    while(query1.next())
    {
        idC = query1.value(0).toString();
    }

    query.exec("DELETE FROM Clients WHERE clientname = '"+clientName+"'");

    m_db.close();

    return idC;
}*/
