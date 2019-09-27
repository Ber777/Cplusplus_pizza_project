#ifndef COURIER_H
#define COURIER_H
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QWidget>
#include <QMessageBox>
#include <QTextBrowser>
#include <QString>

class Courier
{
public:
    Courier();
    void SetCourierName(QString name);
    void SetPassport(QString passport);
    void SetPhone(QString phone);
    void SetBirthday(QString birthday);
    void SetTransport(QString transport);

    QString GetCourierName();
    QString GetBirthday();
    QString GetPassport();
    QString GetPhone();
    QString GetTransport();

    bool GetStatusInDataBase();
    void SetStatusInDataBase(bool isInDataBase);

    bool FormQueryToInsertCourierValue(QString courierName, QString passport, QString birthday, QString phone, QString transport);
    QString FormQueryToSearchCourier(QString courierName, QString passport, QString birthday, QString phone, QString transport);
    QStringList FormQueryToSearchCourierInfo(QString idCourier);
    QString GetId();

    bool SaveInDataBase();
    bool Find();

    void UnInitialazeVales();

private:
    QString m_courierName;
    QString m_passport;
    QString m_phone;
    QString m_id;
    QString m_birthday;
    QString m_transport;
    bool m_isInDataBase;
    QSqlDatabase m_db;
};

#endif // COURIER_H
