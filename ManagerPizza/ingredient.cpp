#include "ingredient.h"

Ingredient::Ingredient()
{

}

void Ingredient::SetIngredientName(QString ingredientName)
{
    m_ingredientName = ingredientName;
}

void Ingredient::SetSum(QString sum)
{
    m_sum = sum;
}

QString Ingredient::GetIngredientName()
{
    return m_ingredientName;
}

QString Ingredient::GetSum()
{
    return m_sum;
}

QString Ingredient::GetId()
{
    return m_id;
}
