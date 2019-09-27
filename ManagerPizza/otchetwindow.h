#ifndef OTCHETWINDOW_H
#define OTCHETWINDOW_H

#include <QMainWindow>
#include <Worker.h>
#include <Order.h>
#include <workerdatamapper.h>
#include <orderdatamapper.h>
#include <qfile.h>
#include <qtextstream.h>
#include <workerservice.h>

namespace Ui {
class OtchetWindow;
}

class OtchetWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OtchetWindow(QWidget *parent = 0);
    ~OtchetWindow();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::OtchetWindow *ui;
    Worker worker;
    Order order;
    WorkerDataMapper workerDataMapper;
    WorkerService workerService;
    OrderDataMapper orderDataMapper;
    unsigned int m_countOtchet;
    void CheckInput(QString pass);
};

#endif // OTCHETWINDOW_H
