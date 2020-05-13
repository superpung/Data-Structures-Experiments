/*******************************************************************************
* FileName:         Graph.cpp
* Author:           李晓鹏
* Student Number:   3019244114
* Date:             2020/04/22 14:19:55
* Version:          v1.0
* Description:      Data Structure Experiment #11
*******************************************************************************/

#include "Graph.h"
#include <iostream>

Graph::Graph(int max_v){
    num_v = max_v;
    num_e = 0;
    VexList = new VertexNode[num_v + 1];
    for (int i = 1; i <= num_v; i++) {
        VexList[i].firstAdj = NULL;
        VexList[i].flag = false;
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
}

void Graph::addedge(int s, int t, int w){
    // from s to t
    EdgeNode* newEdge1 = new EdgeNode;
    newEdge1->weight = w;
    newEdge1->vAdj = s;
    newEdge1->vertex = t;

    newEdge1->next = VexList[s].firstAdj;
    VexList[s].firstAdj = newEdge1;

    // from t to s
    EdgeNode* newEdge2 = new EdgeNode;
    newEdge2->weight = w;
    newEdge2->vAdj = t;
    newEdge2->vertex = s;

    newEdge2->next = VexList[t].firstAdj;
    VexList[t].firstAdj = newEdge2;

    num_e++;
}

int Graph::prim(){
    for (int i = 1; i <= num_v; i++)
        VexList[i].flag = false;

    int sum = 0;// weights' addition result
    int min_w;// the minimum of weights
    int* visited = new int[num_v];// choose the vertexes into this array
    int index = 0;// the number of chosen vertexes

    // choose the start vertex
    for (int i = 1; i <= num_v; i++) {
        if (VexList[i].firstAdj) {
            visited[index++] = i;
            VexList[i].flag = true;// the start vertex is visited
            break;
        }
    }

    // Prim's algorithm
    // when vertexes aren't fully chosen
    while (index < num_v) {
        // search the minimum weight from chosen vertexes
        // search the first weight to initialize min_w
        // initializing min_w must be here, or min_w will be unexpectedly initialized when i changes
        for (int i = 0; i < index; i++) {
            EdgeNode* p = VexList[visited[i]].firstAdj;
            while (VexList[p->vertex].flag && p->next) {
                p = p->next;
            }
            if (VexList[p->vertex].flag)// while ended when p->next is NULL
                continue;
            else {
                min_w = p->weight;// cannot define min_w randomly
                visited[index] = p->vertex;// the min_w's destination is visited too
                break;
            }
        }
        
        // update the minimum weight from each vertex's link
        for (int i = 0; i < index; i++) {
            EdgeNode* p = VexList[visited[i]].firstAdj;
            while (p) {
                if (p->weight <= min_w && !VexList[p->vertex].flag) {
                    min_w = p->weight;
                    visited[index] = p->vertex;
                }
                p = p->next;
            }    
        }

        VexList[visited[index]].flag = true;// updating flag must be here
        index++;// have chosen another one vertex
        sum += min_w;
    }

    delete[] visited;
    return sum;
}

int Graph::kruskal(){
    int sum = 0;// weights' addition result
    EdgeNode* edges = new EdgeNode[num_e];// choose the edges into this array
    int index = 0;// the number of chosen edges
    int begin, end;// to combine set
    int* set = new int[num_v + 1];

    // initialize set
    for (int i = 1; i <= num_v; i++)
        set[i] = i;
    // initialize edges
    for (int i = 1; i <= num_v; i++) {
        EdgeNode* p = VexList[i].firstAdj;
          
        // store weights from this vertex's link
        while (p) {
            if (p->vertex > i) {
                edges[index].vAdj = i;
                edges[index].vertex = p->vertex;
                edges[index].weight = p->weight;
                index++;
            }
            p = p->next;
        }    
    }

    // bubble sort
    for (int i = 0; i < num_e; i++) {
        for (int j = i + 1; j < num_e; j++) {
            if (edges[i].weight > edges[j].weight) {
                EdgeNode temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    // add edges beginning with the minimum
    for (int i = 0, j = 0; i < num_e && j < num_v; i++) {
        if (set[edges[i].vAdj] != set[edges[i].vertex]) {
            sum += edges[i].weight;
            begin = set[edges[i].vAdj];
            end = set[edges[i].vertex];
            for (int k = 1; k <= num_v; k++) {
                if (set[k] == end)// must be begin and end, and don't be set[*]
                    set[k] = begin;
            }
            j++;
        }
    }
       
    delete[] set;
    delete[] edges;
    return sum;
}