#ifndef ADMINISTRATIONVIEW_H
#define ADMINISTRATIONVIEW_H

#include <QWidget>

namespace Ui {
class administrationView;
}

class administrationView : public QWidget
{
    Q_OBJECT

public:
    explicit administrationView(QWidget *parent = nullptr);
    ~administrationView();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::administrationView *ui;
};

#endif // ADMINISTRATIONVIEW_H
