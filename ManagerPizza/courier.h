#ifndef COURIER_H
#define COURIER_H

#include <QWidget>
#include <QMessageBox>
#include <QTextBrowser>
#include <QString>
class Courier
{
public:
    QString m_courierName;
    Courier();
    void SetCourierName(QString name);
    void SetPassport(QString passport);
    void SetPhone(QString phone);
    void SetTransport(QString transport);
    void SetCourierSalary(QString salary);
    //void SetBirthday(QString birthday);

    /*QString GetCourierName();
    QString GetBirthday();
    QString GetPassport();
    QString GetPhone();
    QString GetTransport();*/

    QString GetId();
    QString GetCourierName();
    QString GetPassport();
    QString GetTransport();
    QString GetCourierSalary();
    QString GetPhone();

private:
    QString m_passport;
    QString m_phone;
    QString m_id;
    QString m_transport;
    QString m_salary;
    //QString m_birthday;
};

#endif // COURIER_H
