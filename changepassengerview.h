#ifndef CHANGEPASSENGERVIEW_H
#define CHANGEPASSENGERVIEW_H

#include <QWidget>

namespace Ui {
class ChangePassengerView;
}

class ChangePassengerView : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePassengerView(QWidget *parent = nullptr);
    ~ChangePassengerView();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ChangePassengerView *ui;
};

#endif // CHANGEPASSENGERVIEW_H
