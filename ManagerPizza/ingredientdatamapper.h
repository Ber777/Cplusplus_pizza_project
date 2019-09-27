#ifndef INGREDIENTDATAMAPPER_H
#define INGREDIENTDATAMAPPER_H

#include <QString>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include "QtSql/QSqlError"
#include <QMessageBox>
#include <QDebug>

class IngredientDataMapper
{
public:
    IngredientDataMapper();
    bool CreateDBConnection();
    bool InsertIngredient(QString ingredientName, QString summary);
    int GetIngSum1(QString ingredientName);
    QSqlQuery GetQueryIngName();
    QSqlQuery GetIngSum(QString ingredientName);
    QMap<int, QString> SelectIngredient();

private:
    QSqlDatabase m_db;
};

#endif // INGREDIENTDATAMAPPER_H
