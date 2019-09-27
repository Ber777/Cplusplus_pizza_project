#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "orderwindow.h"
#include "aboutuswindow.h"
#include "orderwindow.h"
#include "seewindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    aboutUsWindow = new AboutUsWindow();
    connect(aboutUsWindow, &AboutUsWindow::firstWindow, this, &MainWindow::show);

    orderWindow = new OrderWindow();
    connect(orderWindow, &OrderWindow::firstWindow, this, &MainWindow::show);

    seeWindow = new SeeWindow();
    connect(seeWindow, &SeeWindow::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    OrderWindow *orderWindow = new OrderWindow;
    orderWindow->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    AboutUsWindow *aboutUsWindow = new AboutUsWindow;
    aboutUsWindow->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_4_clicked()
{
    SeeWindow *seeWindow = new SeeWindow;
    seeWindow->show();
}
