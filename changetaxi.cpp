#include "changetaxi.h"
#include "nullmessagewarn.h"
#include "ui_changetaxi.h"
#include"string"
#include"vector"
#include"dao.h"
#include"administrationview.h"
#include"taxi.h"
#include"middle.h"
using namespace std;



ChangeTaxi::ChangeTaxi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeTaxi)
{
    ui->setupUi(this);
    vector<Person> v;
    Taxi taxi = Taxi();
    DAO::readPerson(taxi,v);
    for (int var = 0; var < v.size(); ++var) {//将司机的信息储存到下拉框中展示给用户
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
        ui->taxiBox->addItem(data);
    }
}

ChangeTaxi::~ChangeTaxi()
{
    delete ui;
}

void ChangeTaxi::on_pushButton_clicked()//撤销修改
{
    administrationView* a = new administrationView();
    a->show();
    ChangeTaxi::close();
}


void ChangeTaxi::on_pushButton_3_clicked()//修改司机的信息
{
    string target = ui->taxiBox->currentText().toStdString();
    string ID = target.substr(target.find_first_of("：")+3,3);//截取出账号
    string password = ui->changePassword->text().toStdString();
    string name = ui->changeName->text().toStdString();
    string license = ui->changeLicense->text().toStdString();
    string fare = ui->changeFare->text().toStdString();
    if(ID == ""||license == ""||password == ""||name == ""||fare == ""){//判空
        Middle::setWarn("0");
        NullMessageWarn* n = new NullMessageWarn();
        n->show();
        return;
    }
    DAO::changeTaxiMessage(ID,password,name,license,fare);
    administrationView* a = new administrationView;
    a->show();
    ChangeTaxi::close();
}


void ChangeTaxi::on_pushButton_2_clicked()//删除指定司机
{
    Taxi taxi = Taxi();
    string target = ui->taxiBox->currentText().toStdString();
    string ID = target.substr(target.find_first_of("：")+3,3);//截取出账号
    DAO::removePassenger(ID,taxi);
    administrationView* a = new administrationView;
    a->show();
    ChangeTaxi::close();
}

