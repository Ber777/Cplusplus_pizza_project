#include "orderdatamapper.h"

OrderDataMapper::OrderDataMapper()
{

}

bool OrderDataMapper::CreateDBConnection()
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

QString OrderDataMapper::FindOrder(QString id)
{
    CreateDBConnection();
    QSqlQuery query;
    QString idO;

    query.exec("SELECT ID_order FROM Orders WHERE ID_order = '"+id+"'");

    while(query.next())
    {
        idO = query.value(0).toString();
    }

    m_db.close();

    return idO;
}

/*bool OrderDataMapper::InsertOrder(QString ID_courier, QString ID_worker, QString clientName, QString address, QString ingredientName, QString pizzaName, QString summary, QString payment)
{
    CreateDBConnection();
    QSqlQuery query;
    bool isAllRight = query.exec("INSERT INTO Orders (ID_courier, ID_worker, clientname, address, ingredientname, pizzaname, summary, payment) VALUES ('"+ID_courier+"', '"+ID_worker+"', '"+clientName+"', '"+address+"', '"+ingredientName+"', '"+pizzaName+"', '"+summary+"', '"+payment+"')");
    return isAllRight;
}*/

bool OrderDataMapper::InsertOrder(QString ID_courier, QString ID_worker, QString ingredientName, QString pizzaName, QString summary, QString payment)
{
    CreateDBConnection();
    QSqlQuery query;
    bool isAllRight = query.exec("INSERT INTO Orders (ID_courier, ID_worker, ingredientname, pizzaname, summary, payment) VALUES ('"+ID_courier+"', '"+ID_worker+"', '"+ingredientName+"', '"+pizzaName+"', '"+summary+"', '"+payment+"')");
    return isAllRight;
}

QMap<int,QString> OrderDataMapper::SelectOrder()
{
    CreateDBConnection();
    QSqlQuery query;
    QMap<int, QString> map;
    int i=0;
    query.exec("SELECT ID_order, ID_courier, ID_worker, summary, pizzaname, ingredientname FROM Orders");
    while (query.next())
    {
        QString ido = query.value(0).toString();
        QString idc = query.value(1).toString();
        QString idw = query.value(2).toString();
        QString sum = query.value(3).toString();
        QString name1 = query.value(4).toString();
        QString name2 = query.value(5).toString();
        QString str = ""+ido+"              "+idc+"                  "+idw+"                        "+sum+"                 "+name2+"         "+name1+"                \n";
        map.insert(i,str);
        i++;
    }

    m_db.close();
    return map;
}

QMap<int, QString> OrderDataMapper::SelectOrderByWorker(QString id)
{
    CreateDBConnection();
    QSqlQuery query;
    QMap<int, QString> map;
    int i=0;
    query.exec("SELECT ID_order, ID_worker FROM Orders WHERE ID_worker = '"+id+"'");
    while (query.next())
    {
        QString ido = query.value(0).toString();
        QString idc = query.value(1).toString();
        QString str = ""+ido+"              "+idc+"                    \n";
        map.insert(i,str);
        i++;
    }

    m_db.close();
    return map;
}

QString OrderDataMapper::DeleteOrder(QString id)
{
    CreateDBConnection();
    QSqlQuery query, query1;
    QString idO;

    query1.exec("SELECT ID_order FROM Orders WHERE ID_order = '"+id+"'");
    while(query1.next())
    {
        idO = query1.value(0).toString();
    }

    query.exec("DELETE FROM Orders WHERE ID_order = '"+id+"'");

    m_db.close();

    return idO;
}

/*QMap<int,QString> OrderDataMapper::SelectOrder()
{
    CreateDBConnection();
    QSqlQuery query;
    QMap<int, QString> map;
    int i=0;
    query.exec("SELECT ID_order, ID_courier, ID_worker, summary, pizzaname, ingredientname, clientname FROM Orders");
    while (query.next())
    {
        QString ido = query.value(0).toString();
        QString idc = query.value(1).toString();
        QString idw = query.value(2).toString();
        QString sum = query.value(3).toString();
        QString name1 = query.value(4).toString();
        QString name2 = query.value(5).toString();
        QString name = query.value(6).toString();
        QString str = ""+ido+"               "+idc+"           "+idw+"              "+sum+"            "+name1+"         "+name2+"         "+name+"                   \n";
        map.insert(i,str);
        i++;
    }

    m_db.close();
    return map;
}*/
