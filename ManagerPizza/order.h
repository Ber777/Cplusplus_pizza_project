#ifndef ORDER_H
#define ORDER_H

#include <QWidget>
#include <QMessageBox>
#include <QTextBrowser>
#include <QString>
#include <client.h>
#include <pizza.h>
#include <payment.h>
#include <ingredient.h>
#include <courier.h>
#include <worker.h>

class Order
{
public:
    int m_summary;

    Order();
    void SetSum(int sum);
    void SetId(QString id);
    //QString GetClientId();
    QString GetIngredientId();
    QString GetPaymentId();
    QString GetPizzaId();
    QString GetCourierId();
    QString GetWorkerId();
    QString GetId();
    int GetSum();

private:
    QString m_id;
    //Client client;
    Ingredient ingredient;
    Pizza pizza;
    Payment pay;
    Courier courier;
    Worker worker;
};

#endif // ORDER_H
