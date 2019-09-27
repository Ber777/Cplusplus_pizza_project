#ifndef INGREDIENTSSERVICE_H
#define INGREDIENTSSERVICE_H

#include <ingredientdatamapper.h>
#include <ingredient.h>

class IngredientsService
{
public:
    IngredientsService();
    QSqlQuery SelectIngName();
    QSqlQuery SelectIngSummary(QString str);
    int SelectIngSummary1(QString str);
    QMap<int, QString> SeeInfo();
    bool SaveInDataBase(QString name, QString summary);

private:
    IngredientDataMapper ingredientDataMapper;
    int m_sum;
    QString m_id;
    QString m_ingredientName;
    QSqlDatabase m_db;
};

#endif // INGREDIENTSSERVICE_H
