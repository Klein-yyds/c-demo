#include "adchangemyself.h"
#include "middle.h"
#include "ui_adchangemyself.h"
#include"administrationview.h"
#include"dao.h"
#include"string"
#include"middle.h"
#include"nullmessagewarn.h"
using namespace std;




AdChangeMyself::AdChangeMyself(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdChangeMyself)
{
    ui->setupUi(this);
}

AdChangeMyself::~AdChangeMyself()
{
    delete ui;
}

void AdChangeMyself::on_pushButton_clicked()//撤回
{
    administrationView* a = new administrationView();
    a->show();
    AdChangeMyself::close();
}


void AdChangeMyself::on_pushButton_2_clicked()
{
    string password = ui->password->text().toStdString();
    string name = ui->name->text().toStdString();
    if(password == ""||name == ""){//判空
        Middle::setWarn("0");
        NullMessageWarn* n = new NullMessageWarn();
        n->show();
        return;
    }
    DAO::changeAdministration(Middle::getID(),password,name);//修改个人信息
    Middle::setName(name);
    Middle::setPassword(password);
    administrationView* a = new administrationView();
    a->show();
    AdChangeMyself::close();
}

