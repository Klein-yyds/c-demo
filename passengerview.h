#ifndef PASSENGERVIEW_H
#define PASSENGERVIEW_H

#include <QWidget>

namespace Ui {
class PassengerView;
}

class PassengerView : public QWidget
{
    Q_OBJECT

public:
    explicit PassengerView(QWidget *parent = nullptr);
    ~PassengerView();

private slots:
    void on_showMapButton_clicked();

    void on_changeMessageButton_clicked();

    void on_changeMessageButton_2_clicked();

private:
    Ui::PassengerView *ui;
};

#endif // PASSENGERVIEW_H
