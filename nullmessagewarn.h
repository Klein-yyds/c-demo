#ifndef NULLMESSAGEWARN_H
#define NULLMESSAGEWARN_H

#include <QWidget>

namespace Ui {
class NullMessageWarn;
}

class NullMessageWarn : public QWidget
{
    Q_OBJECT

public:
    explicit NullMessageWarn(QWidget *parent = nullptr);
    ~NullMessageWarn();

private:
    Ui::NullMessageWarn *ui;
};

#endif // NULLMESSAGEWARN_H
