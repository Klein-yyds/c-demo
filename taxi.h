#ifndef TAXI_H
#define TAXI_H
#include"person.h"
#include"vehicle.h"
#include"string"
using namespace std;


class Taxi : public Person , public Vehicle
{
public:
    Taxi();
    Taxi(string message);
    string getMessageFile();
};

#endif // TAXI_H
