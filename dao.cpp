#include "dao.h"
#include "fstream"
#include "vector"
#include "string"
#include"person.h"
#include"iostream"
#include"algorithm"
using namespace std;




DAO::DAO()
{

}


void DAO::SplitString(const string& s, vector<string>& v, const string& c)//字符串分割方法
{//该方法将会以字符c作为分割的标志,将字符串S分割后，放入容器V
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(string::npos != pos2)
        {
        v.push_back(s.substr(pos1, pos2-pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
        }
    if(pos1 != s.length()){v.push_back(s.substr(pos1));}
}

 void DAO::readPerson(Person& person, vector<Person>& v){
    ifstream ifs;
    string s = person.getMessageFile();
    ifs.open(person.getMessageFile(),ios::in);
    if(!ifs.is_open()){//如果打开不成功
              cout<<"文件打开不成功"<<endl;
        }
    string message;
    while (getline(ifs,message)){
        Person person(message);
        v.push_back(person);
    }
    ifs.close();
}


 int DAO::findStr(vector<string> v, string name){//用来查找vector容器中是否有某元素，有则返回该元素下标，无则返回-1
     vector<string>::iterator iter = find(v.begin(), v.end(), name);
         if (iter == v.end()) {//vector中的最后一个元素在end()-1中，假如等于end()说明走到末尾还没找到该元素
             return -1;
         } else {
             return iter - v.begin();//返回下标
         }
 }


 void DAO::readMap(vector<string>& v){//将地图上的地点名装到容器中
     ifstream ifs;
     ifs.open("Map.txt");
     string message;
     while (getline(ifs,message)){
         string s = message.substr(0,message.find_first_of(" "));
         if(DAO::findStr(v,s) == -1){
            v.push_back(s);
         }
     }
     ifs.close();
 }



 //----------------------------------------------------查找耗时最少路线------------------------------------------------
 string getPoint1(string s) {//获得第一个地名
     string name = s.substr(0, s.find_first_of(' '));
     return name;
 }

 string getPoint2(string s) {//获取第二个地名
     string str = s.substr((s.find_first_of(' ')) + 1);//获取第一个空格后面的字符
     string name = str.substr(0, str.find_first_of(' '));
     return name;
 }

 int getPrice(string s) {//返回路程权值
     string str = s.substr(0, s.find_last_of(' '));//获取最后一个空格前面的字符
     string price = str.substr(str.find_last_of(' '));
     return atoi(price.c_str());
 }

 int getDistance(string s) {//返回路程距离
     string distance = s.substr(s.find_last_of(' '));
     return atoi(distance.c_str());
 }

 int findCheapest(int dist[], int path[], int cheapest[]) {//找到下一个被确定最快路径的顶点
     int num = 0;
     for (int i = 0; i < MAXSIZE; ++i) {//确定第一个还没确定最快的顶点
         if (cheapest[i] == 0){num = i;
             break;
         }
     }
     for (int i = 0; i < MAXSIZE; ++i) {//遍历找到还没确定最快且当前权值最少的顶点
         if (dist[i] != 0 && dist[num] > dist[i] && cheapest[i] == 0) {
             num = i;
         }
     }
     return num;
 }



 Graph* DAO::createGraph() {//创建一个图
     string s;
     Graph *graph = new Graph;
     graph->vexnum = 0;//初始化
     graph->arcnum = 0;
     ifstream ifs1;
     ifs1.open("map.txt", ios::in);
     if (!ifs1.is_open()) {//如果打开不成功
         cout << "第一次文件打开不成功" << endl;
     }
     while (getline(ifs1, s)) {//第一次循环查明左右顶点建立顶点集，明确顶点数量和边的数量
         if (DAO::findStr(graph->vertexes, getPoint1(s)) == -1) {
             graph->vertexes.push_back(getPoint1(s));
             graph->vexnum++;
         }
         if (DAO::findStr(graph->vertexes, getPoint2(s)) == -1) {
             graph->vertexes.push_back(getPoint2(s));
             graph->vexnum++;
         }
         graph->arcnum++;
     }
     ifs1.close();
     ifstream ifs2;
     ifs2.open("map.txt", ios::in);
     if (!ifs2.is_open()) {//如果打开不成功
         cout << "第二次文件打开不成功" << endl;
     }
     for (int i = 0; i < MAXSIZE; ++i) {//将图中的二维数组初始化
         for (int j = 0; j < MAXSIZE; ++j) {
             graph->arcPrice[i][j] = 0;
             graph->arcDistance[i][j] = 0;
         }
     }
     while (getline(ifs2, s)) {//第二次循环完善邻接矩阵
         int num1 = DAO::findStr(graph->vertexes, getPoint1(s));
         int num2 = DAO::findStr(graph->vertexes, getPoint2(s));
         graph->arcDistance[num1][num2] = getDistance(s);
         graph->arcPrice[num1][num2] = getPrice(s);
     }
     return graph;
 }

 void show(Graph *graph, int dist[], int path[], int cheap,string& line) {//递归展示最快路径
     if (path[cheap] == -1) {//找到源点了
         line += graph->vertexes[cheap];
         return;
     } else {
         show(graph, dist, path, path[cheap],line);
         line += "->";
         line += graph->vertexes[cheap];
         return;
     }
 }

 int cheapDistance(Graph *graph, int path[], int endNum) {//返回最快路径的路程
     int distance = 0;
     int num = endNum;
     while (path[num] != -1) {
         distance += graph->arcDistance[path[num]][num];
         num = path[num];
     }
     return distance;
 }







 void DAO::Dijkstra(Graph *graph, string start, string end,string& distance,string& consumingTime,string& line){
     int dist[MAXSIZE] = {0};//记录从源点到当前各顶点最小权值路径的权值
         int path[MAXSIZE] = {-1};//记录从源点到当前各顶点最小权值路径的前驱结点
         int cheapest[MAXSIZE] = {0};//记录是否已经确认权值最少路径
         for (int i = 0; i < MAXSIZE; ++i) {//初始化
             path[i] = -1;
         }
         int startNum = DAO::findStr(graph->vertexes, start);//获取出发地和目的地在地点集中的序号
         int endNum = DAO::findStr(graph->vertexes, end);
         cheapest[startNum] = 1;
         for (int i = 0; i < graph->vexnum; ++i) {//初始化
             if (graph->arcPrice[startNum][i] != 0) {
                 dist[i] = graph->arcPrice[startNum][i];//记录权值
                 path[i] = startNum;
             }
         }
         for (int i = 0; i < graph->vexnum - 1; ++i) {//循环结束条件是出发点所有结点的最快路径均被确认,每次循环确认一个顶点，所以要循环顶点数次
             int cheap = findCheapest(dist, path, cheapest);
             cheapest[cheap] = 1;//标志为最小权值路径确认
             for (int j = 0; j < graph->vexnum; ++j) {
                 if (graph->arcPrice[cheap][j] != 0 && cheapest[j] == 0) {//有到j点的路且到j点的最快路径还为确定
                     if (dist[j] == 0) {
                         path[j] = cheap;
                         dist[j] = dist[cheap] + graph->arcPrice[cheap][j];
                     } else if (dist[cheap] + graph->arcPrice[cheap][j] < dist[j]) {
                         path[j] = cheap;
                         dist[j] = dist[cheap] + graph->arcPrice[cheap][j];
                     }
                 }
             }
         }
         if(path[endNum] == -1){
                 distance+="对不起，您所查找的路线不存在";
                 consumingTime+="对不起，您所查找的路线不存在";
                 line+="对不起，您所查找的路线不存在";
             }else{
                 distance += to_string(cheapDistance(graph, path, endNum));
                 consumingTime += to_string(dist[endNum]);
                 show(graph, dist, path, endNum,line);
             }
 }


 //---------------------------------------------------------------------------------------------------------------

 void DAO::changePassengerMessage(string ID,string name,string password){//修改乘客的信息
     vector<string> data;
     ifstream ifs;
     ifs.open("PassengerMessage.txt",ios::in);
     if(!ifs.is_open()){//如果打开不成功
               cout<<"文件打开不成功"<<endl;
         }
     string message;
     while (getline(ifs,message)){
         data.push_back(message);
     }
     ifs.close();//将所有的乘客的信息都读出来
     ofstream ofs;
     ofs.open("PassengerMessage.txt",ios::out | ios::trunc);//找到特定的乘客信息修改之后进行覆盖性读写
     for (int var = 0; var < data.size(); ++var) {
         if(data[var].substr(0,data[var].find_first_of("-")) == ID){//将该乘客修改之前的状态原封不动地加上去
            ofs<<ID<<"-"<<password<<"-"<<name<<"-"<<data[var].substr(data[var].find_last_of("-")+1)<<endl;
         }else{
            ofs<<data[var]<<endl;
         }
     }
     ofs.close();
 }


 void DAO::removePassenger(string ID,Person& person){
     vector<string> data;
     ifstream ifs;
     ifs.open(person.getMessageFile(),ios::in);
     if(!ifs.is_open()){//如果打开不成功
               cout<<"文件打开不成功"<<endl;
         }
     string message;
     while (getline(ifs,message)){
         data.push_back(message);
     }
     ifs.close();
     ofstream ofs;
     ofs.open(person.getMessageFile(),ios::out | ios::trunc);
     for (int var = 0; var < data.size(); ++var) {
         if(data[var].substr(0,data[var].find_first_of("-")) == ID){
         }else{
            ofs<<data[var]<<endl;
         }
     }
     ofs.close();
 }


 void DAO::addPassenger(string ID,string password,string name){//添加新乘客
     ofstream ofs;
     ofs.open("PassengerMessage.txt",ios::out|ios::app);
     ofs<<ID<<"-"<<password<<"-"<<name<<"-"<<"空闲"<<endl;//默认新创的乘客的状态是空闲
     ofs.close();
 }



 void DAO::changeAdministration(string ID,string password,string name){
     vector<string> data;
     ifstream ifs;
     ifs.open("AdministrationMessage.txt",ios::in);
     if(!ifs.is_open()){//如果打开不成功
               cout<<"文件打开不成功"<<endl;
         }
     string message;
     while (getline(ifs,message)){
         data.push_back(message);
     }
     ifs.close();
     ofstream ofs;
     ofs.open("AdministrationMessage.txt",ios::out | ios::trunc);
     for (int var = 0; var < data.size(); ++var) {
         if(data[var].substr(0,data[var].find_first_of("-")) == ID){
             ofs<<ID<<"-"<<password<<"-"<<name<<endl;
         }else{
            ofs<<data[var]<<endl;
         }
     }
     ofs.close();
 }

 void DAO::changeCondition(string ID, string condition, Person &person)
 {
     vector<string> data;
     ifstream ifs;
     ifs.open(person.getMessageFile(),ios::in);
     if(!ifs.is_open()){//如果打开不成功
               cout<<"文件打开不成功"<<endl;
         }
     string message;
     while (getline(ifs,message)){
         data.push_back(message);
     }
     ifs.close();
     ofstream ofs;
     ofs.open(person.getMessageFile(),ios::out | ios::trunc);
     for (int var = 0; var < data.size(); ++var) {
         if(data[var].substr(0,data[var].find_first_of("-")) == ID){
             ofs<<data[var].substr(0,data[var].find_last_of("-")+1)<<condition<<endl;
         }else{
            ofs<<data[var]<<endl;
         }
     }
     ofs.close();
 }

 string DAO::getCondition(string ID, Person &person)
 {
     vector<string> data;
     ifstream ifs;
     ifs.open(person.getMessageFile(),ios::in);
     if(!ifs.is_open()){//如果打开不成功
               cout<<"文件打开不成功"<<endl;
         }
     string message;
     while (getline(ifs,message)){
         if(message.substr(0,message.find_first_of("-")) == ID){
             ifs.close();
             return message.substr(message.find_last_of("-")+1);
         }
     }
     ifs.close();
     return "";
 }

 void DAO::changeTaxiMessage(string ID, string password, string name, string license, string fare)
 {
     vector<string> data;
     ifstream ifs;
     ifs.open("TaxiMessage.txt",ios::in);
     if(!ifs.is_open()){//如果打开不成功
               cout<<"文件打开不成功"<<endl;
         }
     string message;
     while (getline(ifs,message)){
         data.push_back(message);
     }
     ifs.close();
     ofstream ofs;
     ofs.open("TaxiMessage.txt",ios::out | ios::trunc);
     for (int var = 0; var < data.size(); ++var) {
         if(data[var].substr(0,data[var].find_first_of("-")) == ID){
             ofs<<ID<<"-"<<password<<"-"<<name<<"-"<<license<<"-"<<fare<<"-";
             ofs<<data[var].substr(data[var].find_last_of("-")+1)<<endl;;
         }else{
            ofs<<data[var]<<endl;
         }
     }
     ofs.close();
 }

 void DAO::addTaxi(string ID, string password, string name, string license, string fare)//添加司机的信息
 {
     ofstream ofs;
     ofs.open("TaxiMessage.txt",ios::out|ios::app);
     ofs<<ID<<"-"<<password<<"-"<<name<<"-"<<license<<"-"<<fare<<"-"<<"空闲"<<endl;//默认新创的乘客的状态是空闲
     ofs.close();
 }





// void DAO::changeTaxiCondition(string ID, string condition)
// {
//     vector<string> data;
//     ifstream ifs;
//     ifs.open("TaxiMessage.txt",ios::in);
//     if(!ifs.is_open()){//如果打开不成功
//               cout<<"文件打开不成功"<<endl;
//         }
//     string message;
//     while (getline(ifs,message)){
//         data.push_back(message);
//     }
//     ifs.close();
//     ofstream ofs;
//     ofs.open("TaxiMessage.txt",ios::out | ios::trunc);
//     for (int var = 0; var < data.size(); ++var) {
//         if(data[var].substr(0,data[var].find_first_of("-")) == ID){
//             ofs<<data[var].substr(0,data[var].find_last_of("-")+1)<<condition<<endl;
//         }else{
//            ofs<<data[var]<<endl;
//         }
//     }
//     ofs.close();
// }





