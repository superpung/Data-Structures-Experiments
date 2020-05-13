/*******************************************************************************
* FileName:         Graph.cpp
* Author:           李晓鹏
* Student Number:   3019244114
* Date:             2020/04/29 14:08:55
* Version:          v1.0
* Description:      Data Structure Experiment #12
*******************************************************************************/

#include "Graph.h"
#include <iostream>

Graph::Graph(int max_v){
    num_v = max_v;
    VexList = new VertexNode[num_v + 1];
    inDegree = new int[num_v + 1];
    result_topology = new int[num_v];
    for (int i = 1; i <= num_v; i++) {
        VexList[i].firstAdj = NULL;
        inDegree[i] = 0;
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
    delete[] result_topology;
}

void Graph::addedge(int s, int t, int w){
    EdgeNode* newEdge = new EdgeNode;
    newEdge->weight = w;
    newEdge->vertex = t;

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

int* Graph::topological(){
    int count = getV();
    int index = 0;
    int index_r = 0;
    int i, j, k;
    int* topology = new int[count];
    int* inDeg = new int[count];

    for (i = 1; i <= num_v; i++)
        inDeg[i] = inDegree[i];

    while (index_r < count) {
        // push into stack
        for (i = 1; i <= count; i++) {
            if (!inDeg[i]) {
                for (j = 0; j < count; j++) {
                    if (i == topology[j])
                        break;
                }
                if (j == count) {
                    // pop out of stack
                    if (index_r) {
                        for (k = count - 1; k > index; k--)
                            topology[k] = topology[k - 1];
                    }
                    topology[index++] = i;
                }
            }
        }

        // pop out of stack
        result_topology[index_r++] = topology[--index];

        // delete vertex
        EdgeNode* p = VexList[result_topology[index_r - 1]].firstAdj;
        while (p) {
            inDeg[p->vertex]--;
            p = p->next;
        }
    }

    delete[] topology;
    delete[] inDeg;
    return result_topology;
}