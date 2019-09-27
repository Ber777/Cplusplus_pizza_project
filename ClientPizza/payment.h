#ifndef PAYMENT_H
#define PAYMENT_H

#include <QString>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include "QtSql/QSqlError"

class Payment
{
public:
    Payment();
    void SetPaymentName(QString paymentName);
    QString GetPaymentName();
    QString GetId();
    QSqlQuery GetQueryPaymentName();

private:
    QSqlDatabase m_db;
    QString m_id;
    QString m_paymentName;
};

#endif // PAYMENT_H
