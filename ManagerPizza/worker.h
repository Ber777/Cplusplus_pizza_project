#ifndef WORKER_H
#define WORKER_H

#include <QWidget>
#include <QMessageBox>
#include <QTextBrowser>
#include <QString>

class Worker
{
public:
    Worker();
    void SetWorkerName(QString name);
    void SetPassport(QString passport);
    void SetPhone(QString phone);
    //void SetBirthday(QString birthday);
    void SetPosition(QString position);
    void SetSalary(QString salary);
    void SetId(QString id);

    bool GetStatusInDataBase();
    void SetStatusInDataBase(bool isInDataBase);

    QString GetWorkerName();
    //QString GetBirthday();
    QString GetPassport();
    QString GetPhone();
    QString GetPosition();
    QString GetSalary();

    QString GetId();

private:
    QString m_workerName;
    QString m_passport;
    QString m_phone;
    QString m_id;
    QString m_position;
    QString m_salary;
    //QString m_birthday;
     bool m_isInDataBase; // флаг если  находится в базе
};

#endif // WORKER_H
