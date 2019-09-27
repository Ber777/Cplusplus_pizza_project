#ifndef ABOUTUSWINDOW_H
#define ABOUTUSWINDOW_H

#include <QMainWindow>

namespace Ui {
class AboutUsWindow;
}

class AboutUsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AboutUsWindow(QWidget *parent = 0);
    ~AboutUsWindow();

signals:
     void firstWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AboutUsWindow *ui;
};

#endif // ABOUTUSWINDOW_H
