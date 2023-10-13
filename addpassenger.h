#ifndef ADDPASSENGER_H
#define ADDPASSENGER_H

#include <QWidget>

namespace Ui {
class AddPassenger;
}

class AddPassenger : public QWidget
{
    Q_OBJECT

public:
    explicit AddPassenger(QWidget *parent = nullptr);
    ~AddPassenger();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddPassenger *ui;
};

#endif // ADDPASSENGER_H
