#include "vehicle.h"

Vehicle::Vehicle()
{

}

string Vehicle::getLicenseNumber()
{
    return licenseNumber;
}

string Vehicle::getFare()
{
    return fare;
}

string Vehicle::getCondition()
{
    return condition;
}

void Vehicle::setLicenseNumber(string licenseNumber)
{
    Vehicle::licenseNumber = licenseNumber;
}

void Vehicle::setFare(string fare)
{
    Vehicle::fare = fare;
}

void Vehicle::setCondition(string condition)
{
    Vehicle::condition = condition;
}
