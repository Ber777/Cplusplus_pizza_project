#ifndef SEEWINDOW_H
#define SEEWINDOW_H

#include <QMainWindow>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include "QtSql/QSqlError"
#include <order.h>
#include <orderservice.h>
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

namespace Ui {
class SeeWindow;
}

class SeeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SeeWindow(QWidget *parent = 0);
    bool CreateDBConnection();
    ~SeeWindow();

signals:
    void firstWindow();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    //void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::SeeWindow *ui;
    QSqlDatabase m_db;
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
};

#endif // SEEWINDOW_H
