#ifndef ADDRESSWINDOW_H
#define ADDRESSWINDOW_H

#include <QMainWindow>
#include <client.h>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include "QtSql/QSqlError"
#include <QMessageBox>

namespace Ui {
class AddressWindow;
}

class AddressWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddressWindow(QWidget *parent = 0);
    bool CreateDBConnection();

    ~AddressWindow();
signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddressWindow *ui;
    QSqlDatabase m_db1;
    Client client;
};

#endif // ADDRESSWINDOW_H

