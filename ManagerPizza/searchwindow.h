#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QMainWindow>
#include <client.h>
#include <clientservice.h>
#include <courier.h>
#include <order.h>
#include <orderservice.h>
#include <courierservice.h>
#include <worker.h>
#include <workerservice.h>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include "QtSql/QSqlError"

namespace Ui {
class SearchWindow;
}

class SearchWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SearchWindow(QWidget *parent = 0);
    ~SearchWindow();

signals:
    void firstWindow();

private slots:
    void on_pushButton_5_clicked();

    //void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::SearchWindow *ui;
    QSqlDatabase m_db;
    //Client client;
    //ClientService clientService;
    Courier courier;
    CourierService courierService;
    Worker worker;
    WorkerService workerService;
    Order order;
    OrderService orderService;
};

#endif // SEARCHWINDOW_H
