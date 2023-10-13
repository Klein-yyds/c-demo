#include "addtaxiview.h"
#include "nullmessagewarn.h"
#include "ui_addtaxiview.h"
#include"string"
#include"administrationview.h"
#include"middle.h"
#include"dao.h"

AddTaxiView::AddTaxiView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddTaxiView)
{
    ui->setupUi(this);
}

AddTaxiView::~AddTaxiView()
{
    delete ui;
}

void AddTaxiView::on_pushButton_clicked()//撤回到上一个界面
{
    administrationView* a = new administrationView();
    a->show();
    AddTaxiView::close();
}


void AddTaxiView::on_pushButton_2_clicked()//添加司机
{
    string ID = ui->ID->text().toStdString();
    string password = ui->password->text().toStdString();
    string name = ui->name->text().toStdString();
    string license = ui->license->text().toStdString();
    string fare = ui->fare->text().toStdString();
    if(ID == ""||license == ""||password == ""||name == ""||fare == ""){//判空
        Middle::setWarn("0");
        NullMessageWarn* n = new NullMessageWarn();
        n->show();
        return;
    }
    DAO::addTaxi(ID,password,name,license,fare);
    administrationView* a = new administrationView();
    a->show();
    AddTaxiView::close();
}

