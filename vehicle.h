#ifndef VEHICLE_H
#define VEHICLE_H
#include"string"
using namespace std;



class Vehicle//交通工具类,假如还有时间的话可以添加其他交通工具继承这个类,对交通管理系统进行进一步扩展
{
public:
    Vehicle();
private:
    string licenseNumber;//车牌号码
    string fare;//收费情况
    string condition;//表示是否在接单状态
public:
    string getLicenseNumber();
    string getFare();
    string getCondition();
    void setLicenseNumber(string licenseNumber);
    void setFare(string fare);
    void setCondition(string condition);
};

#endif // VEHICLE_H
