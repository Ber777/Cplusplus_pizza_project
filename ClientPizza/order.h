#ifndef ORDER_H
#define ORDER_H
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QWidget>
#include <QMessageBox>
#include <QTextBrowser>
#include <QString>
#include <Client.h>
#include <pizza.h>
#include <payment.h>
#include <Ingredients.h>
//#include <Courier.h>
//#include <Worker.h>

class Order
{
public:
    int m_summary;

    Order();
    void SetSum(int sum);
    QString GetClientId();
    QString GetIngredientId();
    QString GetId();
    int GetSum();

    bool InsertOrder(QString id, QString name, QString address, QString ingName, QString pizzaName, QString summary, QString paymentName);
    QMap<int, QString> GetOrders();
    bool SaveInDataBase();
    bool Find();

private:
    QString m_id;
    Client client;
    Ingredients ingredient;
    Pizza pizza;
    Payment pay;
    bool m_isInDataBase;
    QSqlDatabase m_db;
};

#endif // ORDER_H
