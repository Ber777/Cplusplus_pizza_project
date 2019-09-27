#include "ingredientsservice.h"

IngredientsService::IngredientsService()
{

}

QSqlQuery IngredientsService::SelectIngName()
{
    QSqlQuery *qry = new QSqlQuery(m_db);
    *qry = ingredientDataMapper.GetQueryIngName();
    return *qry;
}

QSqlQuery IngredientsService::SelectIngSummary(QString str)
{
    QSqlQuery *qry = new QSqlQuery(m_db);
    *qry = ingredientDataMapper.GetIngSum(str);
    return *qry;
}

int IngredientsService::SelectIngSummary1(QString str)
{
    int summary = ingredientDataMapper.GetIngSum1(str);
    return summary;
}

QMap<int, QString> IngredientsService::SeeInfo()
{
    QMap<int, QString> map;
    map = ingredientDataMapper.SelectIngredient();
    return map;
}

bool IngredientsService::SaveInDataBase(QString name, QString summary)
{
    bool isRightQuery = ingredientDataMapper.InsertIngredient(name, summary);
    if(isRightQuery)
        return true;
    else
        return false;
}
