#include "taxiview.h"
#include "passenger.h"
#include "qstandarditemmodel.h"
#include "taxi.h"
#include "taxiwork.h"
#include "ui_taxiview.h"
#include"string"
#include"vector"
#include"dao.h"
#include <iostream>
#include <ostream>
#include"fstream"
#include"middle.h"
#include"mainwindow.h"
using namespace std;


TaxiView::TaxiView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaxiView)
{
        ui->setupUi(this);
        //--------------------以下为设置表格 -----------------------
        QStringList headers;
        headers<<"账号"<<"密码"<<"姓名"<<"当前状态";
        QStandardItemModel* model = new QStandardItemModel();
        ui->passengerTable->setModel(model);
        model->setHorizontalHeaderLabels(headers);
        vector<string> data;
        ifstream ifs;
        ifs.open("PassengerMessage.txt",ios::in);
        if(!ifs.is_open()){//如果打开不成功
                  cout<<"文件打开不成功"<<endl;
            }
        string message;
        while (getline(ifs,message)){
            data.push_back(message);
        }
        ifs.close();//读取所有的乘客信息
        for (int var = 0; var < data.size(); ++var) {
            vector<string> v;
            DAO::SplitString(data[var],v,"-");//将信息按短横线分开后放到各自应该放大位置去
            if(v[3] == "需要乘车"){//假如为需要乘车的乘客将会被展示
                QList<QStandardItem*> addItems;
                QString ID = QString::fromUtf8(v[0].c_str(),v[0].length());
                QString password = QString::fromUtf8(v[1].c_str(),v[1].length());
                QString name = QString::fromUtf8(v[2].c_str(),v[2].length());
                QString condition = QString::fromUtf8(v[3].c_str(),v[3].length());
                addItems<<new QStandardItem(QString(ID).arg(var));
                addItems<<new QStandardItem(QString(password).arg(var));
                addItems<<new QStandardItem(QString(name).arg(var));
                addItems<<new QStandardItem(QString(condition).arg(var));
                model->appendRow(addItems);
                string s = "账号：";
                s+=v[0];
                s+="   姓名：";
                s+=v[2];
                QString total = QString::fromUtf8(s.c_str(),s.length());
                ui->choicePassenger->addItem(total);
            }
        }
        ui->passengerTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//此表格中的信息自适应
        TaxiView::setWindowTitle("欢迎司机使用本交通管理系统");
}

TaxiView::~TaxiView()
{
    delete ui;
}

void TaxiView::on_pushButton_2_clicked()
{
            string passen = ui->choicePassenger->currentText().toStdString();
            string pas = passen.substr(passen.find_first_of("：")+3,3);//截取出账号
            Taxi taxi = Taxi();
            string p = "正在进行乘客";
            p+=pas;
            p+="的订单";
            DAO::changeCondition(Middle::getID(),p,taxi);
            Passenger passenger = Passenger();
            DAO::changeCondition(pas,"乘车中",passenger);//修改对应乘客的订单
            TaxiWork* t = new TaxiWork();
            t->show();
            TaxiView::close();
}


void TaxiView::on_pushButton_clicked()
{
    MainWindow* m = new MainWindow();
        m->show();
        TaxiView::close();
}

