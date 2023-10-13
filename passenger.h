#ifndef PASSENGER_H
#define PASSENGER_H
#include"string"
#include"person.h"
using namespace std;


class Passenger : public Person
{
private:
    string condition;//表示当前订单状态，有空闲，需要乘车以及乘车中三种状态
public:
    Passenger();
    Passenger(string Message);
    string getMessageFile();
    string getCondition();
    void setCondition(string condition);
};

#endif // PASSENGER_H
