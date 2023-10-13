#ifndef ADDTAXIVIEW_H
#define ADDTAXIVIEW_H

#include <QWidget>

namespace Ui {
class AddTaxiView;
}

class AddTaxiView : public QWidget
{
    Q_OBJECT

public:
    explicit AddTaxiView(QWidget *parent = nullptr);
    ~AddTaxiView();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddTaxiView *ui;
};

#endif // ADDTAXIVIEW_H
