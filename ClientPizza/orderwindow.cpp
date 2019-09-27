#include "orderwindow.h"
#include "ui_orderwindow.h"
#include "ui_addresswindow.h"

OrderWindow::OrderWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrderWindow)
{
    ui->setupUi(this);

    addressWindow = new AddressWindow();
    connect(addressWindow, &AddressWindow::firstWindow, this, &OrderWindow::show);
}

OrderWindow::~OrderWindow()
{
    delete ui;
}

bool OrderWindow::CreateDBConnection()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:\\Qt\\databasePizza.db");
    if (!m_db.open())
    {
        qDebug() << "Cannot open database:" << m_db.lastError();
        return false;
    }

    //qDebug() << "USPEX";
    return true;
}

void OrderWindow::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}

void OrderWindow::on_pushButton_3_clicked()
{
    CreateDBConnection();
    model->setQuery(ing.GetQueryIngName());
    ui->comboBox->setModel(model);
    m_db.close();
}

void OrderWindow::on_pushButton_5_clicked()
{
    CreateDBConnection();
    model1->setQuery(pizza.GetQueryPizzaName());
    ui->comboBox_2->setModel(model1);
    m_db.close();
}

void OrderWindow::on_pushButton_2_clicked()
{
    CreateDBConnection();

    QString ingName = ui->comboBox->currentText();
    QString pizzaName = ui->comboBox_2->currentText();
    QString payName = ui->comboBox_3->currentText();

    ing.SetIngredientName(ingName);
    pizza.SetPizzaName(pizzaName);
    pay.SetPaymentName(payName);

    std::string str = ing.GetIngredientName().toStdString();
    std::string str2 = pizza.GetPizzaName().toStdString();

    str.erase(str.length()-9);
    str2.erase(str2.length()-10);

    QString str1 = QString::fromStdString(str);
    QString str3 = QString::fromStdString(str2);

    int sumOfIng = ing.GetQueryIngSummary1(str1);
    int sumOfPizza = pizza.GetQueryPizzaSummary1(str3);

    order.m_summary = sumOfIng + sumOfPizza;
    ui->lineEdit->setText(QString::number(order.m_summary));
    m_db.close();
}

void OrderWindow::on_pushButton_4_clicked()
{
    CreateDBConnection();
    QMessageBox msgBox;
    QString idc = "1";
    QString string1 = " ";
    QString string2 = " ";

    QString ingName = ui->comboBox->currentText();
    QString pizzaName = ui->comboBox_2->currentText();
    QString payName = ui->comboBox_3->currentText();

    ing.SetIngredientName(ingName);
    pizza.SetPizzaName(pizzaName);
    pay.SetPaymentName(payName);

    std::string str = ing.GetIngredientName().toStdString();
    std::string str2 = pizza.GetPizzaName().toStdString();
    std::string str5 = pay.GetPaymentName().toStdString();

    str.erase(str.length()-9);
    str2.erase(str2.length()-10);

    QString str1 = QString::fromStdString(str);
    QString str3 = QString::fromStdString(str2);
    QString str10 = QString::fromStdString(str5);

    /*test2.prepare("INSERT INTO Orders (ID_client, clientname, address, ingredientname, pizzaname, summary, payment) VALUES (:idc, :name, :address, :str1, :str3, :sumOrder, :pay)");
    test2.first();
    test2.bindValue(":idc", idc);
    test2.bindValue(":name", client.SelectClientName(string1));
    test2.bindValue(":address", client.SelectClientAddress(string2));
    test2.bindValue(":str1", str1);
    test2.bindValue(":str3", str3);
    test2.bindValue(":sumOrder", m_summary1);
    test2.bindValue(":pay", str10);*/

    QString strOrderSum = QString::number(order.m_summary);

    bool a = order.InsertOrder(idc, client.SelectClientName(string1), client.SelectClientAddress(string2), str1, str3, strOrderSum, str10);

    if(a)
    {
        msgBox.setText("Ваш заказ успешно оформлен");
        msgBox.exec();
    }

    else
        QMessageBox::warning(this,"Внимание", "Ваш заказ не оформлен, обратитесь в тех. поддержку");
}

void OrderWindow::on_pushButton_6_clicked()
{
    AddressWindow *addressWindow = new AddressWindow;
    addressWindow->show();
}

void OrderWindow::on_pushButton_7_clicked()
{
    CreateDBConnection();
    model2->setQuery(pay.GetQueryPaymentName());
    ui->comboBox_3->setModel(model2);
    m_db.close();
}
