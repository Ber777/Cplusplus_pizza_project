#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QWidget>
#include <QMessageBox>
#include <QTextBrowser>
#include <QString>

class Ingredient
{
public:
    Ingredient();
    void SetIngredientName(QString ingredientName);
    void SetSum(QString sum);
    QString GetIngredientName();
    QString GetId();
    QString GetSum();

private:
    QString m_sum;
    QString m_id;
    QString m_ingredientName;
};

#endif // INGREDIENT_H
