#ifndef GRAPH_H
#define GRAPH_H
#include"string"
#include"vector";
int const MAXSIZE = 22;//顶点最大数量
using namespace std;


class Graph//地图
{
public:
    vector<string> vertexes;//顶点集
    int arcDistance[MAXSIZE][MAXSIZE];//邻接矩阵存距离
    int arcPrice[MAXSIZE][MAXSIZE];//邻接矩阵存价格
    int vexnum;//当前顶点数量
    int arcnum;//当前边的数量
public:
    Graph();
};

#endif // GRAPH_H
