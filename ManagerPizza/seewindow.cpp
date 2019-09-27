#include "seewindow.h"
#include "ui_seewindow.h"

SeeWindow::SeeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SeeWindow)
{
    ui->setupUi(this);
}

SeeWindow::~SeeWindow()
{
    delete ui;
}

void SeeWindow::on_pushButton_8_clicked()
{
    this->close();
    emit firstWindow();
}

/*void SeeWindow::on_pushButton_clicked()
{
    ui->plainTextEdit->insertPlainText("ID_заказа ID_курьера ID_работника Сумма заказа Ингридиент Пицца                    Имя клиента" "\n");

    for(int i=0; i < orderService.SeeInfo().size();i++)
    {
        ui->plainTextEdit->insertPlainText(orderService.SeeInfo()[i]);
    }
}*/

void SeeWindow::on_pushButton_clicked()
{
    ui->plainTextEdit->insertPlainText("ID_заказа ID_курьера ID_работника Сумма заказа Ингридиент Пицца" "\n");

    for(int i=0; i < orderService.SeeInfo().size();i++)
    {
        ui->plainTextEdit->insertPlainText(orderService.SeeInfo()[i]);
    }
}

void SeeWindow::on_pushButton_3_clicked()
{
    ui->plainTextEdit_2->insertPlainText("ID_курьера Паспорт_курьера Телефон_курьера Зарплата_курьера Транспорт_курьера  Имя_курьера"           "\n");

    for(int i=0; i < courierService.SeeInfo().size();i++)
    {
        ui->plainTextEdit_2->insertPlainText(courierService.SeeInfo()[i]);
    }
}

void SeeWindow::on_pushButton_4_clicked()
{
    ui->plainTextEdit_3->insertPlainText("ID_работника Паспорт_работника Телефон_работника Зарплата Должность_работника  Имя_работника"           "\n");

    for(int i=0; i < workerService.SeeInfo().size();i++)
    {
        ui->plainTextEdit_3->insertPlainText(workerService.SeeInfo()[i]);
    }
}

/*void SeeWindow::on_pushButton_7_clicked()
{
    ui->plainTextEdit_4->insertPlainText("ID_клиента Телефон_клиента     Имя_клиента                                                                Адрес_клиента"                "\n");

    for(int i=0; i < clientService.SeeInfo().size();i++)
    {
        ui->plainTextEdit_4->insertPlainText(clientService.SeeInfo()[i]);
    }
}*/

void SeeWindow::on_pushButton_6_clicked()
{
    ui->plainTextEdit_5->insertPlainText("ID_ингредиента Цена Имя_ингредиента" "\n");

    for(int i=0; i < ingredientsService.SeeInfo().size();i++)
    {
        ui->plainTextEdit_5->insertPlainText(ingredientsService.SeeInfo()[i]);
    }
}

void SeeWindow::on_pushButton_5_clicked()
{
    ui->plainTextEdit_6->insertPlainText("ID_пиццы Цена Имя_пиццы" "\n");

    for(int i=0; i < pizzaService.SeeInfo().size();i++)
    {
        ui->plainTextEdit_6->insertPlainText(pizzaService.SeeInfo()[i]);
    }
}
