#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H
#include"string"
#include"person.h"
using namespace std;


class Administration : public Person
{
public:
    Administration();
    Administration(string message);
    string getMessageFile();
};

#endif // ADMINISTRATION_H
