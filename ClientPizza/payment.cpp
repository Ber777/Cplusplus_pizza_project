#include "payment.h"

Payment::Payment()
{

}

void Payment::SetPaymentName(QString paymentName)
{
    m_paymentName = paymentName;
}

QString Payment::GetPaymentName()
{
    return m_paymentName;
}

QString Payment::GetId()
{
    return m_id;
}
QSqlQuery Payment::GetQueryPaymentName()
{
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT paymentname FROM Payment");
    qry->exec();
    qry->first();
    m_db.close();
    return *qry;
}
