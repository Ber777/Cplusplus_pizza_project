#include "addresswindow.h"
#include "ui_addresswindow.h"

AddressWindow::AddressWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddressWindow)
{
    ui->setupUi(this);
}

AddressWindow::~AddressWindow()
{
    delete ui;
}

bool AddressWindow::CreateDBConnection()
{
    m_db1 = QSqlDatabase::addDatabase("QSQLITE");
    m_db1.setDatabaseName("C:\\Qt\\databasePizza.db");
    if (!m_db1.open())
    {
        qDebug() << "Cannot open database:" << m_db1.lastError();
        return false;
    }

    //qDebug() << "USPEX";
    return true;
}

void AddressWindow::on_pushButton_clicked()
{
    CreateDBConnection();
    QMessageBox msgBox;
    QString stringVal;
    stringVal = ui->lineEdit->text();

    bool b = client.UpdateClientAddress(stringVal);

    if(b)
    {
        msgBox.setText("Ваш адрес доставки изменен успешно");
        msgBox.exec();
    }
    else
        QMessageBox::warning(this,"Внимание", "Адрес доставки не был успешно изменен");
}

void AddressWindow::on_pushButton_2_clicked()
{
    this->close();
    emit firstWindow();
}
