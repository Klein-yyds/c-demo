#include "changepassengerview.h"
#include "nullmessagewarn.h"
#include "ui_changepassengerview.h"
#include"passengerview.h"
#include"string"
#include"middle.h"
#include"dao.h"
using namespace std;

ChangePassengerView::ChangePassengerView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePassengerView)
{
    ui->setupUi(this);
    string name = "名字：";
    string password = "密码：";
    name += Middle::getName();
    password += Middle::getPassword();
    ui->name->setText(QString::fromUtf8(name.c_str(),name.length()));//将当前乘客的信息展示到标签上以便乘客进行判断
    ui->password->setText(QString::fromUtf8(password.c_str(),password.length()));
}

ChangePassengerView::~ChangePassengerView()
{
    delete ui;
}

void ChangePassengerView::on_pushButton_clicked()//返回到上一个界面
{
    PassengerView* p = new PassengerView;
    p->show();
    ChangePassengerView::close();
}


void ChangePassengerView::on_pushButton_2_clicked()//修改乘客信息
{
    string name = ui->changeName->text().toStdString();
    string password = ui->changePassword->text().toStdString();
    if(password == ""||name == ""){//判空
        Middle::setWarn("0");
        NullMessageWarn* n = new NullMessageWarn();
        n->show();
        return;
    }
    DAO::changePassengerMessage(Middle::getID(),name,password);
    Middle::setName(name);
    Middle::setPassword(password);
    PassengerView* p = new PassengerView;
    p->show();
    ChangePassengerView::close();
}

