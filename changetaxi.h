#ifndef CHANGETAXI_H
#define CHANGETAXI_H

#include <QWidget>

namespace Ui {
class ChangeTaxi;
}

class ChangeTaxi : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeTaxi(QWidget *parent = nullptr);
    ~ChangeTaxi();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ChangeTaxi *ui;
};

#endif // CHANGETAXI_H
