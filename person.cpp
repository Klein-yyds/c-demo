#include "person.h"
#include"string"
#include"dao.h"
using namespace std;
Person::Person()
{
    Person::authority = "";
    Person::ID = "";
    Person::name = "";
    Person::password = "";
}

Person::Person(string Message){
    vector<string> data;
    DAO::SplitString(Message,data,"-");
    Person::setID(data[0]);
    Person::setPassword(data[1]);
    Person::setName(data[2]);
}

string Person::getMessageFile(){
    return "";
}

string Person::getID(){
    return Person::ID;
}

string Person::getPassword(){
    return Person::password;
}

string Person::getName(){
    return Person::name;
}

string Person::getAuthority(){
    return Person::authority;
}


void Person::setAuthority(string authority){Person::authority = authority;}

void Person::setID(string ID){Person::ID = ID;}

void Person::setName(string Name){Person::name = Name;}

void Person::setPassword(string Password){Person::password = Password;}
