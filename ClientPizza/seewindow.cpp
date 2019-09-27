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

bool SeeWindow::CreateDBConnection()
{
    m_db2 = QSqlDatabase::addDatabase("QSQLITE");
    m_db2.setDatabaseName("C:\\Qt\\databasePizza.db");
    if (!m_db2.open())
    {
        qDebug() << "Cannot open database:" << m_db2.lastError();
        return false;
    }

    //qDebug() << "USPEX";
    return true;
}

void SeeWindow::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}

void SeeWindow::on_pushButton_2_clicked()
{
    CreateDBConnection();

    /*QSqlQuery query;
    query.exec("SELECT ID_order, summary, ingredientname, pizzaname FROM Orders WHERE ID_client = 1");
    //Выводим значения из запроса
    while (query.next())
    {
    QString ido = query.value(0).toString();
    QString ordsum = query.value(1).toString();
    QString ingdw = query.value(2).toString();
    QString pizza = query.value(3).toString();
    ui->plainTextEdit->insertPlainText(ido+"                  "+ordsum+"                         "+ingdw+"               "+pizza+ "\n");
    }*/

    order.GetOrders();
    ui->plainTextEdit->insertPlainText("ID_заказа     Сумма_заказа       Ингридиент       Пицца" "\n");

    for(int i=0; i < order.GetOrders().size();i++)
    {
        ui->plainTextEdit->insertPlainText(order.GetOrders()[i]);
    }
}
