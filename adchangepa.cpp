#include "adchangepa.h"
#include "ui_adchangepa.h"
#include"administrationview.h"
#include"string"
#include"vector"
#include"dao.h"
#include"middle.h"
#include"person.h"
#include"passenger.h"
#include"nullmessagewarn.h"
using namespace std;




AdChangePa::AdChangePa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdChangePa)
{
    ui->setupUi(this);
    vector<Person> v;
    Passenger passenger = Passenger();
    DAO::readPerson(passenger,v);//获取乘客信息列表
    for (int var = 0; var < v.size(); ++var) {//将乘客信息列表打印到下拉框中
        string message = "";
        message += "账号：";
        message += v[var].getID();
        message += "        ";
        message += "密码：";
        message += v[var].getPassword();
        message += "        ";
        message += "姓名：";
        message += v[var].getName();
        message += "        ";
        QString data = QString::fromUtf8(message.c_str(),message.length());
        ui->passengersList->addItem(data);
    }
}

AdChangePa::~AdChangePa()
{
    delete ui;
}

void AdChangePa::on_pushButton_clicked()
{
    administrationView* a = new administrationView;
    a->show();
    AdChangePa::close();
}


void AdChangePa::on_pushButton_3_clicked()//删除指定乘客
{
    string target = ui->passengersList->currentText().toStdString();
    Passenger passenger = Passenger();
    DAO::removePassenger(target.substr(target.find_first_of("：")+3,3),passenger);
    administrationView* a = new administrationView;
    a->show();
    AdChangePa::close();
}


void AdChangePa::on_pushButton_2_clicked()//修改乘客信息
{
    string target = ui->passengersList->currentText().toStdString();
    string password = ui->changePassword->text().toStdString();
    string name = ui->changeName->text().toStdString();
    if(password == ""||name == ""){//判空
        Middle::setWarn("0");
        NullMessageWarn* n = new NullMessageWarn();
        n->show();
        return;
    }
    DAO::changePassengerMessage(target.substr(target.find_first_of("：")+3,3),name,password);
    administrationView* a = new administrationView;
    a->show();
    AdChangePa::close();
}













