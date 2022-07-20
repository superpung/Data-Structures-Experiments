/*******************************************************************************
* FileName:         Graph.cpp
* Author:           super
* Student Number:   0000000000
* Date:             2020/04/15 14:03:55
* Version:          v2.0
* Description:      Data Structure Experiment #10
*******************************************************************************/

#include "Graph.h"
#include <iostream>

Graph::Graph(int v){
    num = v;
    VexList = new VertexNode[v + 1];
    for (int i = 1; i <= v; i++) {
        VexList[i].inDegree = 0;
        VexList[i].outDegree = 0;
        VexList[i].firstAdj = NULL;
    }
}

Graph::~Graph(){// don't NULL
    for (int i = 1; i <= num; i++) {
        while (VexList[i].firstAdj) {
            EdgeNode* temp = VexList[i].firstAdj;
            VexList[i].firstAdj = temp->link;
            delete temp;
        }
    }
    delete[] VexList;
}

void Graph::addedge(int s, int t, int w){
    EdgeNode* newEdge = new EdgeNode;
    newEdge->cost = w;
    newEdge->dest = t;
    newEdge->link = VexList[s].firstAdj;
    VexList[s].firstAdj = newEdge;

    VexList[s].outDegree++;
    VexList[t].inDegree++;
}

int Graph::getInDegree(int v){
    return VexList[v].inDegree;
}

int Graph::getOutDegree(int v){
    return VexList[v].outDegree;
}

int Graph::access(int s, int t){
    EdgeNode* p = VexList[s].firstAdj;
    if (!p)
        return -1;
    while (p) {
        if (p->dest == t)
            return p->cost;
        p = p->link;
    }
    return -1;
}
