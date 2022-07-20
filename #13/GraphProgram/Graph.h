/*******************************************************************************
* FileName:         Graph.h
* Author:           super
* Student Number:   0000000000
* Date:             2020/05/06 13:44:55
* Version:          v1.0
* Description:      Data Structure Experiment #13
*******************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

class Graph{
private:
    struct EdgeNode {
        int dest;
        int cost;
        EdgeNode* next;
    };
    struct VertexNode {
        EdgeNode* firstAdj;
    };

    VertexNode* VexList;
    int* inDegree;
    int* dij;
    int num_v;
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
     *  向图中加入(s, t)， 权重为w的单向边
        @name addedge(int, int, int)
        @param  arg1 边的顶点1
        @param  arg2 边的顶点2
        @param  arg3 边的权重
        @return  void
    */
    void addedge(int s, int t, int w);

    /**
     *  询问图中节点的个数
        @name int getV()
        @param
        @return  int 图中节点的个数
    */
    int getV();

   /**
    *  询问从1出发，到达各个节点的最短路, 如果无法到达，则路程为-1
       @name int* dijkstra()
       @param
       @return  int* 最段路的结果数组
   */
   int* dijkstra();
};
#endif