#ifndef WORKER_H
#define WORKER_H
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
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
    void SetBirthday(QString birthday);
    void SetPosition(QString position);

    QString GetWorkerName();
    QString GetBirthday();
    QString GetPassport();
    QString GetPhone();
    QString GetPosition();

    bool FormQueryToInsertWorkerValue(QString workerName, QString passport, QString birthday, QString phone, QString position);
    QString FormQueryToSearchWorker(QString workerName, QString passport, QString birthday, QString phone, QString position);
    QStringList FormQueryToSearchWorkerInfo(QString idWorker);

    bool GetStatusInDataBase();
    void SetStatusInDataBase(bool isInDataBase);

    QString GetId();

    bool SaveInDataBase();
    bool Find();

    void UnInitialazeVales();

private:
    QString m_workerName;
    QString m_passport;
    QString m_phone;
    QString m_id;
    QString m_birthday;
    QString m_position;
    bool m_isInDataBase;
    QSqlDatabase m_db;
};

#endif // WORKER_H
