#include "administrationview.h"
#include "ui_administrationview.h"
#include"dao.h"
#include"string"
#include"QTableView"
#include"QStandardItemModel"
#include"passenger.h"
#include"vector"
#include"adchangepa.h"
#include"addpassenger.h"
#include"adchangemyself.h"
#include"iostream"
#include"fstream"
#include"mainwindow.h"
#include"changetaxi.h"
#include"addtaxiview.h"
using namespace std;




administrationView::administrationView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrationView)
{
    ui->setupUi(this);
    //------------------------以下均为设置表格----------------------------
    QStringList headers;
    headers<<"账号"<<"密码"<<"姓名"<<"当前状态";
    QStandardItemModel* model = new QStandardItemModel();
    ui->passengersTable->setModel(model);
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
    ifs.close();
    for (int var = 0; var < data.size(); ++var) {
        QList<QStandardItem*> addItems;
        vector<string> v;
        DAO::SplitString(data[var],v,"-");//将信息按短横线分开后放到各自应该放大位置去
        QString ID = QString::fromUtf8(v[0].c_str(),v[0].length());
        QString password = QString::fromUtf8(v[1].c_str(),v[1].length());
        QString name = QString::fromUtf8(v[2].c_str(),v[2].length());
        QString condition = QString::fromUtf8(v[3].c_str(),v[3].length());
        addItems<<new QStandardItem(QString(ID).arg(var));
        addItems<<new QStandardItem(QString(password).arg(var));
        addItems<<new QStandardItem(QString(name).arg(var));
        addItems<<new QStandardItem(QString(condition).arg(var));
        model->appendRow(addItems);
    }
    //-------------------以上为展示乘客列表,以下为展示司机列表-----------
    QStringList headers_2;
    headers_2<<"账号"<<"密码"<<"姓名"<<"车牌号码"<<"收费情况"<<"当前状态";
    QStandardItemModel* model_2 = new QStandardItemModel();
    ui->taxiTable->setModel(model_2);
    model_2->setHorizontalHeaderLabels(headers_2);
    data.clear();
    ifstream ifs_2;
    ifs_2.open("TaxiMessage.txt",ios::in);
    if(!ifs_2.is_open()){//如果打开不成功
              cout<<"文件打开不成功"<<endl;
        }
    message = "";//初始化
    while (getline(ifs_2,message)){
        data.push_back(message);
    }
    ifs_2.close();
    for (int var = 0; var < data.size(); ++var) {
        QList<QStandardItem*> addItems_2;
        vector<string> v;
        DAO::SplitString(data[var],v,"-");//将信息按短横线分开后放到各自应该放大位置去
        QString ID_2 = QString::fromUtf8(v[0].c_str(),v[0].length());
        QString password_2 = QString::fromUtf8(v[1].c_str(),v[1].length());
        QString name_2 = QString::fromUtf8(v[2].c_str(),v[2].length());
        QString licenseNumber_2 = QString::fromUtf8(v[3].c_str(),v[3].length());
        QString fare_2 = QString::number(stoi(v[4]));
        QString condition_2 = QString::fromUtf8(v[5].c_str(),v[5].length());
        addItems_2<<new QStandardItem(QString(ID_2).arg(var));
        addItems_2<<new QStandardItem(QString(password_2).arg(var));
        addItems_2<<new QStandardItem(QString(name_2).arg(var));
        addItems_2<<new QStandardItem(QString(licenseNumber_2).arg(var));
        addItems_2<<new QStandardItem(QString(fare_2).arg(var));
        addItems_2<<new QStandardItem(QString(condition_2).arg(var));
        model_2->appendRow(addItems_2);
    }
    //以下为使表格中的内容自适应表格宽度
    ui->passengersTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->taxiTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    administrationView::setWindowTitle("欢迎管理员使用本交通管理系统");
}

administrationView::~administrationView()
{
    delete ui;
}

void administrationView::on_pushButton_2_clicked()//跳转到修改乘客信息界面
{
    AdChangePa* a = new AdChangePa();
    a->show();
    administrationView::close();
}


void administrationView::on_pushButton_3_clicked()//跳转到添加乘客界面
{
    AddPassenger* a = new AddPassenger();
    a->show();
    administrationView::close();
}


void administrationView::on_pushButton_clicked()//跳转到修改管理员自己的信息的界面
{
    AdChangeMyself* a = new AdChangeMyself();
    a->show();
    administrationView::close();
}


void administrationView::on_pushButton_6_clicked()//退出登录，返回登录界面
{
    MainWindow* m = new MainWindow();
    m->show();
    administrationView::close();
}


void administrationView::on_pushButton_5_clicked()//跳转到修改司机信息界面
{
    ChangeTaxi* c = new ChangeTaxi();
    c->show();
    administrationView::close();
}








void administrationView::on_pushButton_4_clicked()//跳转到添加一个司机的界面
{
    AddTaxiView* a = new AddTaxiView();
    a->show();
    administrationView::close();
}

