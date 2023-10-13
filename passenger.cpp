#include "passenger.h"
#include"string"
#include"vector"
#include"dao.h"
using namespace std;


Passenger::Passenger()
{

}

 string Passenger::getMessageFile(){
     return "PassengerMessage.txt";
 }

 string Passenger::getCondition()
 {
     return condition;
 }

 void Passenger::setCondition(string condition)
 {
  Passenger::condition = condition;
 }

 Passenger::Passenger(string Message){//读取字符串构建类
    vector<string> data;
    DAO::SplitString(Message,data,"-");
    Passenger::setID(data[0]);
    Passenger::setPassword(data[1]);
    Passenger::setName(data[2]);
 }
