#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <client.h>
#include <clientservice.h>
#include <courier.h>
#include <courierservice.h>
#include <worker.h>
#include <workerservice.h>
#include <order.h>
#include <orderservice.h>

namespace Ui {
class DeleteWindow;
}

class DeleteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteWindow(QWidget *parent = 0);
    ~DeleteWindow();

signals:
    void firstWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    //void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::DeleteWindow *ui;
    //Client client;
    //ClientService clientService;
    Courier courier;
    CourierService courierService;
    Worker worker;
    WorkerService workerService;
    Order order;
    OrderService orderService;
};

#endif // DELETEWINDOW_H
