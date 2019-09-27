#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <seewindow.h>
#include <addwindow.h>
#include <searchwindow.h>
//#include <changewindow.h>
#include <deletewindow.h>
#include <otchetwindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    //void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    SeeWindow *seeWindow;
    AddWindow *addWindow;
    SearchWindow *searchWindow;
    //ChangeWindow *changeWindow;
    DeleteWindow *deleteWindow;
    OtchetWindow *otchetWindow;
};

#endif // MAINWINDOW_H
