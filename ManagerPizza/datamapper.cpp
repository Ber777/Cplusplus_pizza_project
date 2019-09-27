#include "datamapper.h"

DataMapper::DataMapper()
{

}

/*bool DataMapper::CreateDBConnection()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:\\Qt\\Pizza\\databasePizza.db");
    if (!m_db.open())
    {
        qDebug() << "Cannot open database:" << m_db.lastError();
        return false;
    }

    return true;
}*/

/*QString DataMapper::FindCourier(QString courierName)
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

bool DataMapper::InsertCourier(QString courierName, QString passport, QString salary, QString phone, QString transport)
{
    CreateDBConnection();
    QSqlQuery query;
    bool isAllRight = query.exec("INSERT INTO Courier (couriername, passport, salary, phone, transport) VALUES ('"+courierName+"', '"+passport+"', '"+salary+"', '"+phone+"', '"+transport+"')");
    return isAllRight;
}

QMap<int, QString> DataMapper::SelectCourier()
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

QString DataMapper::DeleteCourier(QString courierName)
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
}*/

/*QString DataMapper::FindWorker(QString workerName)
{
    CreateDBConnection();
    QSqlQuery query;
    QString idC;

    query.exec("SELECT ID_worker FROM Workers WHERE workername = '"+workerName+"'");

    while(query.next())
    {
        idC = query.value(0).toString();
    }

    m_db.close();

    return idC;
}

bool DataMapper::InsertWorker(QString workerName, QString passport, QString salary, QString position, QString phone)
{
    CreateDBConnection();
    QSqlQuery query;
    bool isAllRight = query.exec("INSERT INTO Workers (workername, passport, salary, position, phone) VALUES ('"+workerName+"', '"+passport+"', '"+salary+"', '"+position+"', '"+phone+"')");
    return isAllRight;
}

QMap<int, QString> DataMapper::SelectWorker()
{
    CreateDBConnection();
    QSqlQuery query;
    QMap<int, QString> map;
    int i=0;
    query.exec("SELECT ID_worker, passport, phone, salary, position, workername FROM Workers");
    while (query.next())
    {
        QString idw = query.value(0).toString();
        QString pass = query.value(1).toString();
        QString phone = query.value(2).toString();
        QString sal = query.value(3).toString();
        QString pos = query.value(4).toString();
        QString name = query.value(5).toString();
        QString str = ""+idw+"                       "+pass+"               "+phone+"             "+sal+"        "+pos+"                         "+name+"        \n";
        map.insert(i,str);
        i++;
    }

    m_db.close();
    return map;
}

QString DataMapper::DeleteWorker(QString workerName)
{
    CreateDBConnection();
    QSqlQuery query, query1;
    QString idC;

    query1.exec("SELECT ID_worker FROM Workers WHERE workername = '"+workerName+"'");
    while(query1.next())
    {
        idC = query1.value(0).toString();
    }

    query.exec("DELETE FROM Workers WHERE workername = '"+workerName+"'");

    m_db.close();

    return idC;
}*/

/*bool DataMapper::InsertIngredient(QString ingredientName, QString summary)
{
    CreateDBConnection();
    QSqlQuery query;
    bool isAllRight = query.exec("INSERT INTO Ingredients (ingredientname, summary) VALUES ('"+ingredientName+"', '"+summary+"')");
    return isAllRight;
}

QMap<int, QString> DataMapper::SelectIngredient()
{
    CreateDBConnection();
    QSqlQuery query;
    QMap<int, QString> map;
    int i=0;
    query.exec("SELECT ID_ingredient, summary, ingredientname FROM Ingredients");
    while (query.next())
    {
        QString iding = query.value(0).toString();
        QString sum = query.value(1).toString();
        QString name = query.value(2).toString();
        QString str = ""+iding+"                          "+sum+"      "+name+"\n";
        map.insert(i,str);
        i++;
    }

    m_db.close();
    return map;
}

QSqlQuery DataMapper::GetQueryIngName()
{
    CreateDBConnection();
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT ingredientname || ' ' || '+(' || summary || 'р.)' FROM Ingredients");
    qry->exec();
    m_db.close();
    return *qry;
}

QSqlQuery DataMapper::GetIngSum(QString ingredientName)
{
    CreateDBConnection();
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT summary FROM Ingredients WHERE ingredientname = '"+ingredientName+"'");
    qry->exec();
    m_db.close();
    return *qry;
}

int DataMapper::GetIngSum1(QString ingredientName)
{
    CreateDBConnection();
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT summary FROM Ingredients WHERE ingredientname = '"+ingredientName+"'");
    qry->exec();
    qry->first();
    m_db.close();
    return qry->value(0).toInt();
}*/

/*QSqlQuery DataMapper::GetQueryPizName()
{
    CreateDBConnection();
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT pizzaname || ' ' || '+(' || summary || 'р.)' FROM Pizza");
    qry->exec();
    m_db.close();
    return *qry;
}

QSqlQuery DataMapper::GetPizzaSum(QString str)
{
    CreateDBConnection();
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT summary FROM Pizza WHERE pizzaname = '"+str+"'");
    qry->exec();
    m_db.close();
    return *qry;
}

int DataMapper::GetPizzaSum1(QString str)
{
    CreateDBConnection();
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT summary FROM Pizza WHERE pizzaname = '"+str+"'");
    qry->exec();
    m_db.close();
    return qry->value(0).toInt();
}

QMap<int, QString> DataMapper::SelectPizza()
{
    CreateDBConnection();
    QSqlQuery query;
    QMap<int, QString> map;
    int i=0;
    query.exec("SELECT ID_pizza, summary, pizzaname FROM Pizza");
    while (query.next())
    {
        QString idpiz = query.value(0).toString();
        QString sum = query.value(1).toString();
        QString name = query.value(2).toString();
        QString str = ""+idpiz+"               "+sum+"    "+name+"\n";
        map.insert(i,str);
        i++;
    }

    m_db.close();
    return map;
}

bool DataMapper::InsertPizza(QString pizzaName, QString summary)
{
    CreateDBConnection();
    QSqlQuery query;
    bool isAllRight = query.exec("INSERT INTO Pizza (pizzaname, summary) VALUES ('"+pizzaName+"', '"+summary+"')");
    return isAllRight;
}*/

/*QString DataMapper::FindClient(QString clientName)
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

QMap<int, QString> DataMapper::SelectClient()
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

QString DataMapper::DeleteClient(QString clientName)
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

/*bool DataMapper::InsertOrder(QString ID_courier, QString ID_worker, QString clientName, QString address, QString ingredientName, QString pizzaName, QString summary, QString payment)
{
    CreateDBConnection();
    QSqlQuery query;
    bool isAllRight = query.exec("INSERT INTO Orders (ID_courier, ID_worker, clientname, address, ingredientname, pizzaname, summary, payment) VALUES ('"+ID_courier+"', '"+ID_worker+"', '"+clientName+"', '"+address+"', '"+ingredientName+"', '"+pizzaName+"', '"+summary+"', '"+payment+"')");
    return isAllRight;
}

QMap<int,QString> DataMapper::SelectOrder()
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

