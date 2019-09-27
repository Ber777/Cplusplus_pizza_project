#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    seeWindow = new SeeWindow();
    connect(seeWindow, &SeeWindow::firstWindow, this, &MainWindow::show);

    addWindow = new AddWindow();
    connect(seeWindow, &SeeWindow::firstWindow, this, &MainWindow::show);

    searchWindow = new SearchWindow();
    connect(searchWindow, &SearchWindow::firstWindow, this, &MainWindow::show);

    /*changeWindow = new ChangeWindow();
    connect(changeWindow, &ChangeWindow::firstWindow, this, &MainWindow::show);*/

    deleteWindow = new DeleteWindow();
    connect(deleteWindow, &DeleteWindow::firstWindow, this, &MainWindow::show);

    otchetWindow = new OtchetWindow();
    connect(otchetWindow, &OtchetWindow::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    SeeWindow *seeWindow = new SeeWindow;
    seeWindow->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    AddWindow *addWindow = new AddWindow;
    addWindow->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    SearchWindow *searchWindow = new SearchWindow;
    searchWindow->show();
}

/*void MainWindow::on_pushButton_4_clicked()
{
    ChangeWindow *changeWindow = new ChangeWindow;
    changeWindow->show();
}*/

void MainWindow::on_pushButton_5_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_6_clicked()
{
    DeleteWindow *deleteWindow = new DeleteWindow;
    deleteWindow->show();
}

void MainWindow::on_pushButton_7_clicked()
{
    OtchetWindow *otchetWindow = new OtchetWindow;
    otchetWindow->show();
}
