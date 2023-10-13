#ifndef TAXIVIEW_H
#define TAXIVIEW_H

#include <QWidget>

namespace Ui {
class TaxiView;
}

class TaxiView : public QWidget
{
    Q_OBJECT

public:
    explicit TaxiView(QWidget *parent = nullptr);
    ~TaxiView();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::TaxiView *ui;
};

#endif // TAXIVIEW_H
