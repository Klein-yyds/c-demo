#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"iostream"
#include"string"
#include"dao.h"
#include"middle.h"
#include"person.h"
#include"passenger.h"
#include"administration.h"
#include"passengerview.h"
#include"administrationview.h"
#include"nullmessagewarn.h"
#include"taxi.h"
#include"taxiview.h"
#include"taxiwork.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->IDLine->setPlaceholderText("请输入你的账号");
    ui->passwordLine->setPlaceholderText("请输入你的密码");
    ui->passwordLine->setEchoMode(QLineEdit::Password);               //密码，一般是用小黑点覆盖你所输入的字符
    MainWindow::setWindowTitle("欢迎用户使用本交通管理系统");
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{

    if(ui->IDLine->text() == "" || ui->passwordLine->text() == ""){//对所有的消息进行判空
        Middle::setWarn("0");
        NullMessageWarn* n = new NullMessageWarn();
        n->show();
        return;
    }
    int a = ui->comboBox->currentIndex();
    vector<Person> v;//根据用户选择的不同的登录角色,对登录方法进行多态处理
    if(ui->comboBox->currentIndex() == 0){//获取对应登录角色的人员信息列表
        Middle::setAuthority("管理员");
        Administration administration = Administration();
        DAO::readPerson(administration,v);
    }else if(ui->comboBox->currentIndex() == 1){
        Middle::setAuthority("乘客");
        Passenger passenger = Passenger();
        DAO::readPerson(passenger,v);
    }else if(ui->comboBox->currentIndex() == 2){
        Middle::setAuthority("司机");
        Taxi taxi = Taxi();
        DAO::readPerson(taxi,v);
    }
    for (int var = 0; var < v.size(); ++var) {
        if(ui->IDLine->text().toStdString() == v[var].getID() &&
                ui->passwordLine->text().toStdString() == v[var].getPassword())//账号密码匹配
        {
            Middle::setID(v[var].getID());
            Middle::setPassword(v[var].getPassword());
            Middle::setName(v[var].getName());
            if(ui->comboBox->currentIndex() == 0){//根据选择的角色的身份不同进入不同的界面
                administrationView* a = new administrationView;
                a->show();
                MainWindow::close();

            }else if(ui->comboBox->currentIndex() == 1){
                PassengerView* p = new PassengerView;
                p->show();
                MainWindow::close();
            }else if(ui->comboBox->currentIndex() == 2){
                Taxi taxi = Taxi();
                string judge = DAO::getCondition(v[var].getID(),taxi);
                if(judge == "空闲"){
                    TaxiView* t = new TaxiView();
                    t->show();
                    MainWindow::close();
                }else{
                    TaxiWork* t = new TaxiWork();
                    t->show();
                    MainWindow::close();
                }
            }
            return;
        }
    }
    Middle::setWarn("1");//还能运行到这里说明账号密码不匹配或者根本就不存在该账号
    NullMessageWarn* n = new NullMessageWarn();
    n->show();
    return;
}

