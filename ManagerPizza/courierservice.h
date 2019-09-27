#ifndef COURIERSERVICE_H
#define COURIERSERVICE_H

#include <courierdatamapper.h>
#include <courier.h>

class CourierService
{
public:
    CourierService();
    bool CreateDBConnection();
    bool Find(QString str);
    QMap<int, QString> SeeInfo();
    bool Delete(QString str);
//    bool SaveInDataBase(QString name, QString passport, QString salary, QString phone, QString transport);
    bool SaveInDataBase(Courier &courier);
    //void Update(QString name);

private:
    CourierDataMapper courierDataMapper;
    Courier courier;
    QString m_id;
    bool m_isInDataBase;
};

#endif // COURIERSERVICE_H
