#include "ingredients.h"

Ingredients::Ingredients()
{

}

void Ingredients::SetIngredientName(QString ingredientName)
{
    m_ingredientName = ingredientName;
}

void Ingredients::SetSum(int sum)
{
    m_sum = sum;
}

QString Ingredients::GetIngredientName()
{
    return m_ingredientName;
}

int Ingredients::GetSum()
{
    return m_sum;
}

QString Ingredients::GetId()
{
    return m_id;
}

QSqlQuery Ingredients::GetQueryIngName()
{
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT ingredientname || ' ' || '+(' || summary || 'р.)' FROM Ingredients");
    qry->exec();
    qry->first();
    m_db.close();
    return *qry;
}

QSqlQuery Ingredients::GetQueryIngSummary(QString str)
{
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT summary FROM Ingredients WHERE ingredientname = '"+str+"'");
    qry->exec();
    qry->first();
    m_db.close();
    return *qry;
}

int Ingredients::GetQueryIngSummary1(QString str)
{
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT summary FROM Ingredients WHERE ingredientname = '"+str+"'");
    qry->exec();
    qry->first();
    m_db.close();
    return qry->value(0).toInt();
}

