/*******************************************************************************
* FileName:         Graph.h
* Author:           super
* Student Number:   0000000000
* Date:             2020/04/15 14:03:55
* Version:          v2.0
* Description:      Data Structure Experiment #10
*******************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

class Graph{
private:
    struct EdgeNode {
        int dest;
        int cost;
        EdgeNode* link;
    };
    struct VertexNode {
        int inDegree, outDegree;
        EdgeNode* firstAdj;
    };

    VertexNode* VexList;
    int num;
public:
    /**
     *  初始化一张有向图
        @name Graph(int max_v)
        @param arg1  图中最多的节点数
        @return
    */
    Graph(int max_v);


    /**
     *  析构函数
        @name ~Graph()
        @param
        @return
    */
    ~Graph();


    /**
     *  添加一条s到t，权重为w的边
        @name void addedge(int, int, int)
        @param arg1  边的起始节点
        @param arg2  边的终止节点
        @param arg3  边的权重
        @return
    */
    void addedge(int s, int t, int w);


    /**
     *  获得一个顶点的出度
        @name getOutDegree(int)
        @param arg1 需要获取出度的节点
        @return
    */
    int getOutDegree(int v);

    /**
     *  获得一个顶点的入度
        @name getInDegree(int)
        @param arg1 需要获取入度的节点
        @return
    */
    int getInDegree(int v);


    /**
     *  判断s到t是否有直接连接的边，如果有，则返回边的长度，如果没有则返回-1
        @name  int access(int, int)
        @param arg1 起始顶点
        @param arg2 终止顶点
        @return 相连边的长度
    */
    int access(int s, int t);

};


#endif