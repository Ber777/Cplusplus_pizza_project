#ifndef PAYMENT_H
#define PAYMENT_H

#include <QString>

class Payment
{
public:
    Payment();
    void SetPaymentName(QString paymentName);
    QString GetPaymentName();
    QString GetId();

private:
    QString m_id;
    QString m_paymentName;
};

#endif // PAYMENT_H
