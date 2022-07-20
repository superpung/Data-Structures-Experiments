/*******************************************************************************
* FileName:         Graph.h
* Author:           super
* Student Number:   0000000000
* Date:             2020/04/22 14:19:55
* Version:          v1.0
* Description:      Data Structure Experiment #11
*******************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H


class Graph{
private:
    struct EdgeNode {
        int vAdj, vertex;
        int weight;
        EdgeNode* next;
    };
    struct VertexNode {
        bool flag;
        EdgeNode* firstAdj;
    };

    VertexNode* VexList;
    int num_v, num_e;

public:
    /**
     *  类的构造函数
        @name Graph(int)
        @param  arg1 最大的顶点数
        @return
    */
    Graph(int max_v);

    /**
     *  类的析构函数
        @name ~Graph()
        @param
        @return
    */
    ~Graph();

    /**
     *  向图中加入(s, t)， 权重为w的双向边
        @name addedge(int, int, int)
        @param  arg1 边的顶点1
        @param  arg2 边的顶点2
        @param  arg3 边的权重
        @return  void
    */
    void addedge(int s, int t, int w);

    /**
     *  询问这张图的最小生成树(prim算法实现)
        @name int prim()
        @param
        @return  int 最小生成树的权值
    */
    int prim();

    /**
     *  询问这张图的最小生成树(kruskal实现)
        @name int kruskal()
        @param
        @return  int 最小生成树的权值
    */
    int kruskal();
};

#endif