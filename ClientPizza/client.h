#ifndef CLIENT_H
#define CLIENT_H
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QWidget>
#include <QMessageBox>
#include <QTextBrowser>
#include <QString>

class Client
{
public:
    Client();
    void SetClientName(QString clientName);
    void SetPhone(QString phone);
    void SetAdress(QString adress);
    //void SetLogin(QString login);
    //void SetPassword(QString password);

    QString GetId();

    QString SelectClientName(QString name);
    QString SelectClientAddress(QString address);
    bool UpdateClientAddress(QString address);

    bool SaveInDataBase();

    bool CreateDBConnection();

private:
    QString m_id;
    QString m_clientName;
    QString m_address;
    QString m_phone;
    //QString m_login;
    //QString m_password;
    QSqlDatabase m_db;    
};

#endif // CLIENT_H
