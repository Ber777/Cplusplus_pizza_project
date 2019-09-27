#include "addwindow.h"
#include "ui_addwindow.h"
#include <QMessageBox>

AddWindow::AddWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);
}

AddWindow::~AddWindow()
{
    delete ui;
}

void AddWindow::on_pushButton_6_clicked()
{
    this->close();
    emit firstWindow();
}

void AddWindow::on_pushButton_2_clicked()
{
    QMessageBox my;

    QString strCourierName = ui->lineEdit_5->text();
    QString strCourierPassport = ui->lineEdit->text();
    QString strCourierPhone = ui->lineEdit_2->text();
    QString strCourierSalary = ui->lineEdit_3->text();
    QString strCourierTransport = ui->lineEdit_4->text();

    courier.SetCourierName(strCourierName);
    courier.SetPassport(strCourierPassport);
    courier.SetPhone(strCourierPhone);
    courier.SetCourierSalary(strCourierSalary);
    courier.SetTransport(strCourierTransport);

    //bool isCourierAdd = courierService.SaveInDataBase(courier.GetCourierName(), courier.GetPassport(), courier.GetCourierSalary(), courier.GetPhone(), courier.GetTransport());

    bool isCourierAdd = courierService.SaveInDataBase(courier);


    if(isCourierAdd)
    {
        my.setText("Курьер добавлен в БД");
        my.exec();
    }
    else
        QMessageBox::warning(this, "Внимание" ,"Курьер не был добавлен в БД");
}

void AddWindow::on_pushButton_3_clicked()
{
    QMessageBox my;

    QString strWorkerName = ui->lineEdit_9->text();
    QString strWorkerPassport = ui->lineEdit_6->text();
    QString strWorkerPhone = ui->lineEdit_8->text();
    QString strWorkerSalary = ui->lineEdit_10->text();
    QString strWorkerPosition = ui->lineEdit_7->text();

    worker.SetWorkerName(strWorkerName);
    worker.SetPassport(strWorkerPassport);
    worker.SetPhone(strWorkerPhone);
    worker.SetSalary(strWorkerSalary);
    worker.SetPosition(strWorkerPosition);

    bool isWorkerAdd = workerService.SavaInDataBase(worker.GetWorkerName(), worker.GetPassport(), worker.GetSalary(), worker.GetPosition(), worker.GetPhone());

    if(isWorkerAdd)
    {
        my.setText("Работник добавлен в БД");
        my.exec();
    }
    else
        QMessageBox::warning(this, "Внимание" ,"Работник не был добавлен в БД");
}

void AddWindow::on_pushButton_4_clicked()
{
    QMessageBox my;

    QString strIngName = ui->lineEdit_12->text();
    QString strIngSum = ui->lineEdit_11->text();

    ingredient.SetIngredientName(strIngName);
    ingredient.SetSum(strIngSum);

    bool isIngAdd = ingredientsService.SaveInDataBase(ingredient.GetIngredientName(), ingredient.GetSum());

    if(isIngAdd)
    {
        my.setText("Ингредиент добавлен в БД");
        my.exec();
    }
    else
        QMessageBox::warning(this, "Внимание" ,"Ингредиент не был добавлен в БД");
}

void AddWindow::on_pushButton_5_clicked()
{
    QMessageBox my;

    QString strPizzaName = ui->lineEdit_13->text();
    QString strPizzaSum = ui->lineEdit_14->text();

    pizza.SetPizzaName(strPizzaName);
    pizza.SetPizzaSum(strPizzaSum);

    bool isPizzaAdd = pizzaService.SaveInDataBase(pizza.GetPizzaName(), pizza.GetPizzaSum());

    if(isPizzaAdd)
    {
        my.setText("Пицца добавлена в БД");
        my.exec();
    }
    else
        QMessageBox::warning(this, "Внимание" ,"Пицца не была добавлена в БД");
}

void AddWindow::on_pushButton_7_clicked()
{
    model->setQuery(pizzaService.SelectPizName());
    ui->comboBox->setModel(model);
    m_db.close();
}

void AddWindow::on_pushButton_8_clicked()
{
    model1->setQuery(ingredientsService.SelectIngName());
    ui->comboBox_2->setModel(model1);
    m_db.close();
}

void AddWindow::on_pushButton_clicked()
{
    QMessageBox my;

    //QString strClientName = ui->lineEdit_18->text();
    QString strIdCo = ui->lineEdit_15->text();
    QString strIdW = ui->lineEdit_19->text();
    //QString strAddr = ui->lineEdit_17->text();
    QString strPay = ui->lineEdit_16->text();
    QString strPiz = ui->comboBox->currentText();
    QString strIng = ui->comboBox_2->currentText();

    //client.SetClientName(strClientName);
    courier.SetCourierName(strIdCo);
    worker.SetWorkerName(strIdW);
    //client.SetAdress(strAddr);
    payment.SetPaymentName(strPay);
    pizza.SetPizzaName(strPiz);
    ingredient.SetIngredientName(strIng);

    std::string str = pizza.GetPizzaName().toStdString();
    std::string str2 = ingredient.GetIngredientName().toStdString();

    str.erase(str.length()-10);
    str2.erase(str2.length()-9);

    QString str1 = QString::fromStdString(str);
    QString str3 = QString::fromStdString(str2);


    int sumOfIng = pizzaService.SelectPizSummary1(str1);
    int sumOfPizza = ingredientsService.SelectIngSummary1(str3);
    int sum = sumOfIng + sumOfPizza;

    QString summary = QString::number(sum);

    //bool isOrderAdd = orderService.SaveInDataBase(courier.GetCourierName(), worker.GetWorkerName(), client.GetClientName(), client.GetAddress(), str3, str1, summary, payment.GetPaymentName());

    bool isOrderAdd = orderService.SaveInDataBase(courier.GetCourierName(), worker.GetWorkerName(), str3, str1, summary, payment.GetPaymentName());

    if(isOrderAdd)
    {
        my.setText("Заказ добавлен в БД");
        my.exec();
    }
    else
        QMessageBox::warning(this, "Внимание" ,"Заказ не был добавлен в БД");
}
