#include "searchwindow.h"
#include "ui_searchwindow.h"

#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QDebug>
#include "QtSql/QSqlError"
#include "QMessageBox"

SearchWindow::SearchWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SearchWindow)
{
    ui->setupUi(this);
}

SearchWindow::~SearchWindow()
{
    delete ui;
}

void SearchWindow::on_pushButton_5_clicked()
{
    this->close();
    emit firstWindow();
}

/*void SearchWindow::on_pushButton_2_clicked()
{
    QMessageBox my;

    QString strClientName = ui->lineEdit_2->text();

    client.SetClientName(strClientName);

    bool isClientFind = clientService.Find(client.GetClientName());

    if(isClientFind)
    {
        my.setText("Клиент найден в БД");
        my.exec();
    }
    else
        QMessageBox::warning(this, "Внимание" ,"Клиент не найден в БД");
}*/

void SearchWindow::on_pushButton_3_clicked()
{
    QMessageBox my;

    QString strCourierName = ui->lineEdit_3->text();

    courier.SetCourierName(strCourierName);

    bool isCourierFind = courierService.Find(courier.GetCourierName());

    if(isCourierFind)
    {
        my.setText("Курьер найден в БД");
        my.exec();
    }
    else
        QMessageBox::warning(this, "Внимание" ,"Курьер не найден в БД");
}

void SearchWindow::on_pushButton_4_clicked()
{
    QMessageBox my;

    QString strWorkerName = ui->lineEdit_4->text();

    worker.SetWorkerName(strWorkerName);

    bool isWorkerFind = workerService.Find(worker.GetWorkerName());

    if(isWorkerFind)
    {
        my.setText("Работник найден в БД");
        my.exec();
    }
    else
        QMessageBox::warning(this, "Внимание" ,"Работник не найден в БД");
}

void SearchWindow::on_pushButton_clicked()
{
    QMessageBox my;

    QString id = ui->lineEdit->text();

    order.SetId(id);

    bool isOrderFind = orderService.Find(order.GetId());

    if(isOrderFind)
    {
        my.setText("Заказ найден в БД");
        my.exec();
    }
    else
        QMessageBox::warning(this, "Внимание" ,"Заказ не найден в БД");

}
