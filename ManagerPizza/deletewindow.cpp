#include "deletewindow.h"
#include "ui_deletewindow.h"

DeleteWindow::DeleteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteWindow)
{
    ui->setupUi(this);
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}

void DeleteWindow::on_pushButton_2_clicked()
{
    QMessageBox my;

    QString strCourierName = ui->lineEdit_2->text();

    courier.SetCourierName(strCourierName);

    bool isCourierDelete = courierService.Delete(courier.GetCourierName());

    if(isCourierDelete)
    {
        my.setText("Курьер удален из БД");
        my.exec();
    }
    else
        QMessageBox::warning(this, "Внимание" ,"Курьер не удален из БД");

}

void DeleteWindow::on_pushButton_5_clicked()
{
    this->close();
    emit firstWindow();
}

void DeleteWindow::on_pushButton_3_clicked()
{
    QMessageBox my;

    QString strWorkerName = ui->lineEdit_3->text();

    worker.SetWorkerName(strWorkerName);

    bool isWorkerDelete = workerService.Delete(worker.GetWorkerName());

    if(isWorkerDelete)
    {
        my.setText("Работник удален из БД");
        my.exec();
    }
    else
        QMessageBox::warning(this, "Внимание" ,"Работник не удален из БД");
}

/*void DeleteWindow::on_pushButton_4_clicked()
{
    QMessageBox my;

    QString strClientName = ui->lineEdit_4->text();

    client.SetClientName(strClientName);

    bool isClientDelete = clientService.Delete(client.GetClientName());

    if(isClientDelete)
    {
        my.setText("Клиент удален из БД");
        my.exec();
    }
    else
        QMessageBox::warning(this, "Внимание" ,"Клиент не удален из БД");
}
*/

void DeleteWindow::on_pushButton_clicked()
{
    QMessageBox my;

    QString id = ui->lineEdit->text();

    order.SetId(id);

    bool isOrderDelete = orderService.Delete(order.GetId());

    if(isOrderDelete)
    {
        my.setText("Заказ удален из БД");
        my.exec();
    }
    else
        QMessageBox::warning(this, "Внимание" ,"Заказ не удален из БД");
}
