#include "addpassenger.h"
#include "nullmessagewarn.h"
#include "ui_addpassenger.h"
#include"string"
#include"vector"
#include"dao.h"
#include"middle.h"
#include"administrationview.h"
using namespace std;




AddPassenger::AddPassenger(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddPassenger)
{
    ui->setupUi(this);
    AddPassenger::move(200,150);
    ui->ID->setPlaceholderText("账号为3为有效数字");
    ui->password->setPlaceholderText("密码为3为有效数字");
    ui->name->setPlaceholderText("请输入你的名字");
}

AddPassenger::~AddPassenger()
{
    delete ui;
}

void AddPassenger::on_pushButton_clicked()//撤回到上一个界面
{
    administrationView* a = new administrationView();//界面跳转
    a->show();
    AddPassenger::close();
}


void AddPassenger::on_pushButton_2_clicked()//添加一个乘客
{
    string ID = ui->ID->text().toStdString();
    string password = ui->password->text().toStdString();
    string name = ui->name->text().toStdString();
    if(ID == ""||password == ""||name == ""){//判空
        Middle::setWarn("0");
        NullMessageWarn* n = new NullMessageWarn();
        n->show();
        return;
    }
    DAO::addPassenger(ID,password,name);
    administrationView* a = new administrationView();
    a->show();
    AddPassenger::close();
}

