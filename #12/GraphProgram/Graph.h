/*******************************************************************************
* FileName:         Graph.h
* Author:           李晓鹏
* Student Number:   3019244114
* Date:             2020/04/29 14:08:55
* Version:          v1.0
* Description:      Data Structure Experiment #12
*******************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

class Graph{
private:
    struct EdgeNode {
        int vertex;
        int weight;
        EdgeNode* next;
    };
    struct VertexNode {
        EdgeNode* firstAdj;
    };

    VertexNode* VexList;
    int* inDegree;
    int* result_topology;
    int num_v;
public:
    /**
     *  类的构造函数
        @name Graph(int)
        @param  arg1 最大的定点数
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
     *  向图中加入(s, t)， 权重为w的单向
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
    *  询问图拓扑排序的结果，并将结果储存在数组中
       @name int* topological()
       @param 
       @return  int* 拓扑排序的结果
   */
   int *topological();
};
#endif