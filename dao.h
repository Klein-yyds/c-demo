#ifndef DAO_H
#define DAO_H
#include"vector"
#include"string"
#include"person.h"
#include"graph.h"
using namespace std;


class DAO//工具类
{
public:
    DAO();
    static void SplitString(const string& s, vector<string>& v, const string& c);
    static void readPerson(Person& p, vector<Person>& v);
    static int findStr(vector<string> v, string name);//用来查找vector容器中是否有某元素，有则返回该元素下标，无则返回-1
    static void readMap(vector<string>& v);
    static void Dijkstra(Graph *graph, string start, string end,string& distance,string& consumingTime,string& line);
    static Graph *createGraph();
    static void changePassengerMessage(string ID,string name,string password);
    static void removePassenger(string ID,Person& person);
    static void addPassenger(string ID,string password,string name);
    static void changeAdministration(string ID,string password,string name);
    static void changeCondition(string ID,string condition,Person& person);
    static string getCondition(string ID,Person& person);
    static void changeTaxiMessage(string ID,string password,string name,string license,string fare);
    static void addTaxi(string ID,string password,string name,string license,string fare);
};

#endif // DAO_H
