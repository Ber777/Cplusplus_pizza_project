#include "pizzadatamapper.h"

PizzaDataMapper::PizzaDataMapper()
{

}

bool PizzaDataMapper::CreateDBConnection()
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

QSqlQuery PizzaDataMapper::GetQueryPizName()
{
    CreateDBConnection();
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT pizzaname || ' ' || '+(' || summary || 'р.)' FROM Pizza");
    qry->exec();
    qry->first();
    m_db.close();
    return *qry;
}

QSqlQuery PizzaDataMapper::GetPizzaSum(QString str)
{
    CreateDBConnection();
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT summary FROM Pizza WHERE pizzaname = '"+str+"'");
    qry->exec();
    qry->first();
    m_db.close();
    return *qry;
}

int PizzaDataMapper::GetPizzaSum1(QString str)
{
    CreateDBConnection();
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT summary FROM Pizza WHERE pizzaname = '"+str+"'");
    qry->exec();
    qry->first();
    m_db.close();
    return qry->value(0).toInt();
}

QMap<int, QString> PizzaDataMapper::SelectPizza()
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

bool PizzaDataMapper::InsertPizza(QString pizzaName, QString summary)
{
    CreateDBConnection();
    QSqlQuery query;
    bool isAllRight = query.exec("INSERT INTO Pizza (pizzaname, summary) VALUES ('"+pizzaName+"', '"+summary+"')");
    return isAllRight;
}
