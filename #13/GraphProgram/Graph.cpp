/*******************************************************************************
* FileName:         Graph.cpp
* Author:           李晓鹏
* Student Number:   3019244114
* Date:             2020/05/06 13:44:55
* Version:          v1.0
* Description:      Data Structure Experiment #13
*******************************************************************************/

#include "Graph.h"
#include <iostream>

Graph::Graph(int max_v){
    num_v = max_v;
    VexList = new VertexNode[num_v + 1];
    inDegree = new int[num_v + 1];
    dij = new int[num_v + 1];
    for (int i = 1; i <= num_v; i++) {
        VexList[i].firstAdj = NULL;
        inDegree[i] = 0;
        if (i == 1)
            dij[i] = 0;
        else
            dij[i] = -1;
    }
}

Graph::~Graph(){
    for (int i = 1; i <= num_v; i++) {
        while (VexList[i].firstAdj) {
            EdgeNode* temp = VexList[i].firstAdj;
            VexList[i].firstAdj = temp->next;
            delete temp;
        }
    }
    delete[] VexList;
    delete[] inDegree;
    delete[] dij;
}

void Graph::addedge(int s, int t, int w){
    EdgeNode* newEdge = new EdgeNode;
    newEdge->cost = w;
    newEdge->dest = t;

    newEdge->next = VexList[s].firstAdj;
    VexList[s].firstAdj = newEdge;

    inDegree[t]++;
}

int Graph::getV(){
    int sum = 0;
    for (int i = 1; i <= num_v; i++) {
        if (VexList[i].firstAdj || inDegree[i])
            sum++;
    }

    return sum;
}

int* Graph::dijkstra(){
    int min, min_index;// mini cost and its index
    int count = getV();// vertexes' number
    int i;
    int left = count - 1;// left vertex(es)
    bool* visit = new bool[count + 1];// is visited?
    EdgeNode* p;
    // init
    for (i = 2; i <= count; i++)
        visit[i] = false;// vertexes aren't visited
    p = VexList[1].firstAdj;
    while (p) {
        dij[p->dest] = p->cost;// direct cost
        p = p->next;
    }
    // update
    while (left--) {
        // init min from lefts
        for (i = 2; i <= count; i++) {
            if (dij[i] >= 0 && !visit[i]) {
                min = dij[i];
                min_index = i;
                break;
            }
        }
        if (i > count)// all but -1 are visited
            break;
        // update min from lefts
        for (i = 2; i <= count; i++) {
            if (dij[i] >= 0 && dij[i] < min && !visit[i]) {
                min = dij[i];
                min_index = i;
            }
        }
        visit[min_index] = true;
        // update dij
        p = VexList[min_index].firstAdj;
        while (p) {
            dij[p->dest] = (p->cost + min < dij[p->dest] || dij[p->dest] == -1) ? 
                           (p->cost + min) : dij[p->dest];// dest, not cost
            p = p->next;
        }
    }
    // shift
    for (i = 0; i < count; i++)
        dij[i] = dij[i + 1];

    delete[] visit;
    return dij;
}