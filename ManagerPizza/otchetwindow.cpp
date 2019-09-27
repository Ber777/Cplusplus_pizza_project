#include "otchetwindow.h"
#include "ui_otchetwindow.h"

OtchetWindow::OtchetWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OtchetWindow)
{
    ui->setupUi(this);
}

OtchetWindow::~OtchetWindow()
{
    delete ui;
}

void OtchetWindow::CheckInput(QString pass)
{
    if(pass.isEmpty())
    {
       QMessageBox::warning(this,"Внимание","Вы не ввели пасспортные данные работника\n");
    }
}

void OtchetWindow::on_pushButton_clicked()
{
    QString passport = ui->lineEdit->text();

    CheckInput(passport);

    m_countOtchet++;
    if(!passport.isEmpty())
    {
        worker.SetPassport(passport);
        //workerDataMapper.GetWorker(worker);
        workerService.GetWorker(worker);

        if(!worker.GetId().isEmpty())
        {
            worker.SetStatusInDataBase(true);
        }
        else
        {
            worker.SetStatusInDataBase(false);
            QMessageBox::warning(this,"Внимание","Данного работника нет в базе\n");
        }
        if(worker.GetStatusInDataBase())
        {
            QStringList listOfWorkers;
            QFile file;

            file.setFileName("C:/otchets/otchet"+QString::number(m_countOtchet)+".txt");
            if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                 QMessageBox::warning(this,"Внимание","Отчет не сформирован \n");
            }

            QTextStream stream(&file);
            QString titelNumber = "Номер работника: ";
            QString titelName = "Имя работника: ";
            QString titelSal = "Зарплата работника: ";
            QString titelPos = "Должность работника: ";
            QString titelPhone = "Телефон работника: ";

            stream<<titelNumber<<worker.GetId()<<"\n"<<titelName<<worker.GetWorkerName()<<"\n"<<
                    titelSal<<worker.GetSalary()<<"\n"<<titelPos<<worker.GetPosition()<<"\n"<<titelPhone<<worker.GetPhone()<<"\n";

            //listOfWorkers = workerDataMapper.FormQueryToSearchWorkerInTableOrders(worker);
            listOfWorkers = workerService.WorkersInOrders(worker);

            QStringList listOfOrders;
            QString titelOrder = "Номера заказов: ";
            QString z = " ";
            //listOfOrders = workerDataMapper.FormQueryToSearchOrdersByWorker(worker);
            listOfOrders = workerService.WorkersOrdersWorkers(worker);
            stream<<titelOrder;
            for(int i=0; i<listOfOrders.size();i++)
            {
                stream<<listOfOrders.at(i)<<z;
            }
            stream<<"\n";

            QMessageBox::warning(this,"Внимание","Отчет сформирован в папке C:\otchets");

        }
    }
    else
    {
        QMessageBox::warning(this,"Внимание","Введите данные для формирования отчета полностью\n");
    }
}

void OtchetWindow::on_pushButton_2_clicked()
{
    this->close();
    emit firstWindow();
}
