#include "middle.h"

Middle::Middle()
{

}


string Middle::getID(){
    return Middle::ID;
}

string Middle::getPassword(){
    return Middle::password;
}

string Middle::getName(){
    return Middle::name;
}

string Middle::getWarn()
{
   return Middle::warn;
}

string Middle::getAuthority(){
    return Middle::authority;
}


void Middle::setAuthority(string authority){Middle::authority = authority;}

void Middle::setID(string ID){Middle::ID = ID;}

void Middle::setName(string Name){Middle::name = Name;}

void Middle::setPassword(string Password){Middle::password = Password;}

void Middle::setWarn(string warn){Middle::warn = warn;}

string Middle::authority = "";
string Middle::ID = "";
string Middle::name = "";
string Middle::password = "";
string Middle::warn = "";
