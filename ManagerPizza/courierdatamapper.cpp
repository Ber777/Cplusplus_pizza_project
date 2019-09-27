#include "courierdatamapper.h"

CourierDataMapper::CourierDataMapper()
{

}

bool CourierDataMapper::CreateDBConnection()
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

QString CourierDataMapper::FindCourier(QString courierName)
{
    CreateDBConnection();
    QSqlQuery query;
    QString idC;

    query.exec("SELECT ID_courier FROM Courier WHERE couriername = '"+courierName+"'");

    while(query.next())
    {
        idC = query.value(0).toString();
    }

    m_db.close();

    return idC;
}

bool CourierDataMapper::InsertCourier(QString courierName, QString passport, QString salary, QString phone, QString transport)
//bool CourierDataMapper::InsertCourier(Courier &courier)
{
    CreateDBConnection();
    QSqlQuery query;
    bool isAllRight = query.exec("INSERT INTO Courier (couriername, passport, salary, phone, transport) VALUES ('"+courierName+"', '"+passport+"', '"+salary+"', '"+phone+"', '"+transport+"')");
    //bool isAllRight = query.exec("INSERT INTO Courier (couriername, passport, salary, phone, transport) VALUES ('"+courier.GetCourierName()+"', '"+courier.GetPassport()+"', '"+courier.GetCourierSalary()+"', '"+courier.GetPhone()+"', '"+courier.GetTransport()+"')");
    return isAllRight;
}

QMap<int, QString> CourierDataMapper::SelectCourier()
{
    CreateDBConnection();
    QSqlQuery query;
    QMap<int, QString> map;
    int i=0;
    query.exec("SELECT ID_courier, passport, phone, salary, transport, couriername FROM Courier");
    while (query.next())
    {
        QString idc = query.value(0).toString();
        QString pass = query.value(1).toString();
        QString phone = query.value(2).toString();
        QString sal = query.value(3).toString();
        QString tran = query.value(4).toString();
        QString name = query.value(5).toString();
        QString str = ""+idc+"                 "+pass+"           "+phone+"         "+sal+"                        "+tran+"                "+name+"        \n";
        map.insert(i,str);
        i++;
    }

    m_db.close();
    return map;
}

QString CourierDataMapper::DeleteCourier(QString courierName)
{
    CreateDBConnection();
    QSqlQuery query, query1;
    QString idC;

    query1.exec("SELECT ID_courier FROM Courier WHERE couriername = '"+courierName+"'");
    while(query1.next())
    {
        idC = query1.value(0).toString();
    }

    query.exec("DELETE FROM Courier WHERE couriername = '"+courierName+"'");

    m_db.close();

    return idC;
}
