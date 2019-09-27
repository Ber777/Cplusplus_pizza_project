#include "aboutuswindow.h"
#include "ui_aboutuswindow.h"

AboutUsWindow::AboutUsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AboutUsWindow)
{
    ui->setupUi(this);
}

AboutUsWindow::~AboutUsWindow()
{
    delete ui;
}

void AboutUsWindow::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}
