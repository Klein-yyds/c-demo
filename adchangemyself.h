#ifndef ADCHANGEMYSELF_H
#define ADCHANGEMYSELF_H

#include <QWidget>

namespace Ui {
class AdChangeMyself;
}

class AdChangeMyself : public QWidget
{
    Q_OBJECT

public:
    explicit AdChangeMyself(QWidget *parent = nullptr);
    ~AdChangeMyself();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AdChangeMyself *ui;
};

#endif // ADCHANGEMYSELF_H
