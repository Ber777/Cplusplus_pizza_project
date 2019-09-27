#ifndef COURIERDATAMAPPER_H
#define COURIERDATAMAPPER_H

#include <QString>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include "QtSql/QSqlError"
#include <QMessageBox>
#include <QDebug>
//#include <courierservice.h>
//#include <courier.h>

class CourierDataMapper
{
public:
    CourierDataMapper();
    bool CreateDBConnection();
    QString FindCourier(QString courierName);
    bool InsertCourier(QString courierName, QString passport, QString salary, QString phone, QString transport);
//    bool InsertCourier(Courier &courier);
    QMap<int, QString> SelectCourier();
    QString DeleteCourier(QString courierName);

private:
    QSqlDatabase m_db;
//    Courier courier;
};

#endif // COURIERDATAMAPPER_H
