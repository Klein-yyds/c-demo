#ifndef ADCHANGEPA_H
#define ADCHANGEPA_H

#include <QWidget>

namespace Ui {
class AdChangePa;
}

class AdChangePa : public QWidget
{
    Q_OBJECT

public:
    explicit AdChangePa(QWidget *parent = nullptr);
    ~AdChangePa();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AdChangePa *ui;
};

#endif // ADCHANGEPA_H
