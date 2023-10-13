#ifndef PERSON_H
#define PERSON_H
#include"string"
using namespace std;

class Person
{
private:
    string authority;
    string ID;
    string password;
    string name;
public:
    Person();
    Person(string message);
    virtual string getMessageFile();//返回存储自己信息的文件的地址

    string getAuthority();
    string getID();
    string getPassword();
    string getName();
    void setAuthority(string authority);
    void setID(string ID);
    void setPassword(string password);
    void setName(string name);
};

#endif // PERSON_H
