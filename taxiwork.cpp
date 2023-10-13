#include "taxiwork.h"
#include "ui_taxiwork.h"
#include"dao.h"
#include"passenger.h"
#include"taxi.h"
#include"string"
#include"string"
#include"taxiview.h"
#include"middle.h"
using namespace std;

TaxiWork::TaxiWork(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaxiWork)
{
    ui->setupUi(this);
    Taxi taxi = Taxi();
    string condition = DAO::getCondition(Middle::getID(),taxi);
    condition+="，请确定将乘客送到目的地后再点击确认订单";
    QString qs = QString::fromUtf8(condition.c_str(),condition.length());
    ui->label->setText(qs);
}

TaxiWork::~TaxiWork()
{
    delete ui;
}

void TaxiWork::on_pushButton_clicked()//订单完成
{
    Taxi taxi = Taxi();
    Passenger passenger = Passenger();
    string condition = DAO::getCondition(Middle::getID(),taxi);
    string pID = condition.substr(18,3);
    DAO::changeCondition(pID,"空闲",passenger);
    DAO::changeCondition(Middle::getID(),"空闲",taxi);
    TaxiView* t = new TaxiView();
    t->show();
    TaxiWork::close();
}

