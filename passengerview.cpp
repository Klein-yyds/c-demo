#include "passengerview.h"
#include "ui_passengerview.h"
#include"string"
#include"vector"
#include"dao.h"
#include"changepassengerview.h"
#include"middle.h"
#include"passenger.h"
#include"mainwindow.h"
using namespace std;

PassengerView::PassengerView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PassengerView)
{
    ui->setupUi(this);
    PassengerView::setWindowTitle("欢迎乘客使用本交通管理系统");
    vector<string> map;
    DAO::readMap(map);
    for (int var = 0; var < map.size(); ++var) {//将地点集合打印到下拉框中 展示给用户
        QString data = QString::fromUtf8(map[var].c_str(),map[var].length());
        ui->startPoint->addItem(data);
        ui->destination->addItem(data);
    }
}

PassengerView::~PassengerView()
{
    delete ui;
}

void PassengerView::on_showMapButton_clicked()
{
    string distance="两地距离：";
    string consumingTime="预计最短耗时：";
    string line="预计最短耗时路线：";
    string s = ui->startPoint->currentText().toStdString();//从界面中或者出发点和目的地的名字
    string end = ui->destination->currentText().toStdString();
    DAO::Dijkstra(DAO::createGraph(),s,end,distance,consumingTime,line);//使用迪杰特斯拉算法对两地之间耗时最短路线进行计算
    ui->distance->setText(QString::fromUtf8(distance.c_str(),distance.length()));//展示计算结果
    ui->consumingTime->setText(QString::fromUtf8(consumingTime.c_str(),consumingTime.length()));
    ui->line->setText(QString::fromUtf8(line.c_str(),line.length()));
    Passenger passenger = Passenger();
    DAO::changeCondition(Middle::getID(),"需要乘车",passenger);//发出订单后修改乘车人的状态为“需要乘车”
}


void PassengerView::on_changeMessageButton_clicked()//乘客进入修改个人信息界面
{
    ChangePassengerView* c = new ChangePassengerView;
    c->show();
    PassengerView::close();
}


void PassengerView::on_changeMessageButton_2_clicked()//退回登录界面
{
    MainWindow* m = new MainWindow();
    m->show();
    PassengerView::close();
}

