#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QMainWindow>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include "QtSql/QSqlError"
#include <client.h>
#include <clientservice.h>
#include <courier.h>
#include <courierservice.h>
#include <worker.h>
#include <workerservice.h>
#include <ingredient.h>
#include <ingredientsservice.h>
#include <pizza.h>
#include <pizzaservice.h>
#include <payment.h>
#include <order.h>
#include <orderservice.h>

namespace Ui {
class AddWindow;
}

class AddWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = 0);
    bool CreateDBConnection();
    ~AddWindow();

signals:
    void firstWindow();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddWindow *ui;
    QSqlDatabase m_db;
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQueryModel *model1 = new QSqlQueryModel(this);
    Order order;
    OrderService orderService;
    //Client client;
    //ClientService clientService;
    Courier courier;
    CourierService courierService;
    Worker worker;
    WorkerService workerService;
    Ingredient ingredient;
    IngredientsService ingredientsService;
    Pizza pizza;
    PizzaService pizzaService;
    Payment payment;
};

#endif // ADDWINDOW_H
