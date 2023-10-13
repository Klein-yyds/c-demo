#include "nullmessagewarn.h"
#include "ui_nullmessagewarn.h"
#include"middle.h"
#include"string"
using namespace std;



NullMessageWarn::NullMessageWarn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NullMessageWarn)
{
    ui->setupUi(this);
    if(Middle::getWarn() == "0"){//信息未补充完整警告
        NullMessageWarn::setWindowTitle("友情提示");
        ui->label->setText("  警告"); //清空字体
        ui->label->setStyleSheet("QLabel{background-color:rgb(139,26,26);}");  //设置样式表
        ui->detail->setText("请补全账号或密码信息");
        ui->widget->setStyleSheet("background-image:url(:/msgbox/warn.png)");//设置图片的背景路径
    }else if(Middle::getWarn() == "1"){//账号密码不匹配或该账号不存在
        NullMessageWarn::setWindowTitle("友情提示");
        ui->label->setText("  警告"); //清空字体
        ui->label->setStyleSheet("QLabel{background-color:rgb(139,26,26);}");  //设置样式表
        ui->detail->setText("密码错误或该账号不存在");
        ui->widget->setStyleSheet("background-image:url(:/msgbox/warn.png)");//设置图片的背景路径
    }else if(Middle::getWarn() == "2"){

    }
}

NullMessageWarn::~NullMessageWarn()
{
    delete ui;
}
