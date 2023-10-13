#ifndef TAXIWORK_H
#define TAXIWORK_H

#include <QWidget>

namespace Ui {
class TaxiWork;
}

class TaxiWork : public QWidget
{
    Q_OBJECT

public:
    explicit TaxiWork(QWidget *parent = nullptr);
    ~TaxiWork();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TaxiWork *ui;
};

#endif // TAXIWORK_H
