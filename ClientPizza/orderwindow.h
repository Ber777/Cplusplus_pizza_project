#ifndef ORDERWINDOW_H
#define ORDERWINDOW_H

#include <QMainWindow>
#include <addresswindow.h>
#include <ingredients.h>
#include <pizza.h>
#include <payment.h>
#include <client.h>
#include <order.h>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include "QtSql/QSqlError"

namespace Ui {
class OrderWindow;
}

class OrderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrderWindow(QWidget *parent = 0);
    bool CreateDBConnection();
    ~OrderWindow();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::OrderWindow *ui;
    AddressWindow *addressWindow;
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQueryModel *model1 = new QSqlQueryModel(this);
    QSqlQueryModel *model2 = new QSqlQueryModel(this);

    QString ingredientName;
    Client client;
    Ingredients ing;
    Pizza pizza;
    Payment pay;
    Order order;
    QSqlDatabase m_db;
    int m_summary1;
};

#endif // ORDERWINDOW_H
