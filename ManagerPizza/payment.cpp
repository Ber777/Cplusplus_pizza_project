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

