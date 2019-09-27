#ifndef INGREDIENTS_H
#define INGREDIENTS_H
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include "QtSql/QSqlError"
#include <QWidget>
#include <QMessageBox>
#include <QTextBrowser>
#include <QString>

class Ingredients
{
public:
    Ingredients();
    void SetIngredientName(QString ingredientName);
    void SetSum(int sum);
    QString GetIngredientName();
    QString GetId();
    int GetSum();

    QSqlQuery GetQueryIngName();
    QSqlQuery GetQueryIngSummary(QString str);
    int GetQueryIngSummary1(QString str);

    bool SaveInDataBase();

private:
    int m_sum;
    QString m_id;
    QString m_ingredientName;
    bool m_isInDataBase;
    //QSqlQueryModel model3;
    QSqlDatabase m_db;
    //QSqlQueryModel model;
};

#endif // INGREDIENTS_H
