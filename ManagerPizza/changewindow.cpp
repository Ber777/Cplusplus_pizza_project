#include "changewindow.h"
#include "ui_changewindow.h"

/*ChangeWindow::ChangeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChangeWindow)
{
    ui->setupUi(this);
}

ChangeWindow::~ChangeWindow()
{
    delete ui;
}

void ChangeWindow::on_pushButton_14_clicked()
{
    this->close();
    emit firstWindow();
}

void ChangeWindow::on_pushButton_12_clicked()
{
    QMessageBox my;

    QString strCourierName = ui->lineEdit->text();

    courier.SetCourierName(strCourierName);

    bool isCourierDelete = courierService.Update(courier.GetCourierName());

    if(isCourierDelete)
    {
        my.setText("ФИО курьера успешно изменено");
        my.exec();
    }
    else
        QMessageBox::warning(this, "Внимание" ,"ФИО курьера не было изменено");
}*/
