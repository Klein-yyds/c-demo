#ifndef MIDDLE_H
#define MIDDLE_H
#include"string"
using namespace std;


class Middle
{
private:
    static string authority;
    static string ID;
    static string password;
    static string name;
    static string warn;
    Middle();
public:
    static string getAuthority();
    static string getID();
    static string getPassword();
    static string getName();
    static string getWarn();
    static void setAuthority(string authority);
    static void setID(string ID);
    static void setPassword(string password);
    static void setName(string name);
    static void setWarn(string warn);
};

#endif // MIDDLE_H
