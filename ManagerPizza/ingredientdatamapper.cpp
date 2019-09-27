#include "ingredientdatamapper.h"

IngredientDataMapper::IngredientDataMapper()
{

}

bool IngredientDataMapper::CreateDBConnection()
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

bool IngredientDataMapper::InsertIngredient(QString ingredientName, QString summary)
{
    CreateDBConnection();
    QSqlQuery query;
    bool isAllRight = query.exec("INSERT INTO Ingredients (ingredientname, summary) VALUES ('"+ingredientName+"', '"+summary+"')");
    return isAllRight;
}

QMap<int, QString> IngredientDataMapper::SelectIngredient()
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

QSqlQuery IngredientDataMapper::GetQueryIngName()
{
    CreateDBConnection();
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT ingredientname || ' ' || '+(' || summary || 'р.)' FROM Ingredients");
    qry->exec();
    m_db.close();
    return *qry;
}

QSqlQuery IngredientDataMapper::GetIngSum(QString ingredientName)
{
    CreateDBConnection();
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT summary FROM Ingredients WHERE ingredientname = '"+ingredientName+"'");
    qry->exec();
    m_db.close();
    return *qry;
}

int IngredientDataMapper::GetIngSum1(QString ingredientName)
{
    CreateDBConnection();
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT summary FROM Ingredients WHERE ingredientname = '"+ingredientName+"'");
    qry->exec();
    qry->first();
    m_db.close();
    return qry->value(0).toInt();
}
