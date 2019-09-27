#ifndef SEEWINDOW_H
#define SEEWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <order.h>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QtSql/QSqlError"

namespace Ui {
class SeeWindow;
}

class SeeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SeeWindow(QWidget *parent = 0);
    bool CreateDBConnection();
    ~SeeWindow();

signals:
     void firstWindow();

private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

private:
    Ui::SeeWindow *ui;
    QSqlDatabase m_db2;
    Order order;
};

#endif // SEEWINDOW_H
