#include "taxi.h"
#include"dao.h"
#include"vector"

Taxi::Taxi()
{

}

Taxi::Taxi(string message)
{
    vector<string> v;
    DAO::SplitString(message,v,"-");
    Taxi::setID(v[0]);
    Taxi::setPassword(v[1]);
    Taxi::setName(v[2]);
    Taxi::setLicenseNumber(v[3]);
    Taxi::setFare(v[4]);
    Taxi::setCondition(v[5]);
}

string Taxi::getMessageFile()
{
return "TaxiMessage.txt";
}
