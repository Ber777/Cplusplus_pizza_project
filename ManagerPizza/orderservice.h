#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H

#include <orderdatamapper.h>
#include <order.h>

class OrderService
{
public:
    OrderService();
    bool Find(QString str);
    QMap<int, QString> SeeInfo();
    //bool SaveInDataBase(QString idC, QString idW, QString name, QString address, QString ingName, QString pizName, QString summary, QString payName);
    bool SaveInDataBase(QString idC, QString idW, QString ingName, QString pizName, QString summary, QString payName);
    bool Delete(QString str);

private:
    OrderDataMapper orderDataMapper;
    Order order;
    QString m_id;
    bool m_isInDataBase;

};

#endif // ORDERSERVICE_H
