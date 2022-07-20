#include <iostream>
#include <cstdio>

#include "Graph.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Graph g(6);

    g.addedge(1, 2, 10);
    g.addedge(1, 3, 20);
    g.addedge(1, 4, 20);
    g.addedge(1, 5, 5);
    g.addedge(2, 3, 1);
    g.addedge(3, 4, 1);
    g.addedge(4, 5, 1);
    g.addedge(6, 1, 1);

    int len = g.getV();
    int *arr = g.dijkstra();

    int r_arr[6] = {0, 10, 11, 12, 5, -1};
    
    if(len == 6){
        cout << "Pass check point 1!" << endl;
    }

    int i;
    for(i = 0; i < len; i++){
        if(arr[i] != r_arr[i]) break;
    }
    if(i == len) cout << "Pass check point 2!" << endl;
    // delete arr;
    // 在这里可以释放 dijkstra 分配的数组

    Graph g1(7);

    g1.addedge(1, 2, 7);
    g1.addedge(1, 3, 9);
    g1.addedge(1, 6, 14);
    g1.addedge(2, 3, 10);
    g1.addedge(2, 4, 15);
    g1.addedge(3, 4, 11);
    g1.addedge(3, 6, 2);
    g1.addedge(4, 5, 6);
    g1.addedge(6, 5, 9);

    int len1 = g1.getV();
    int *arr1 = g1.dijkstra();

    int r_arr1[6] = {0, 7, 9, 20, 20, 11};
    
    if(len1 == 6){
        cout << "Pass check point 3!" << endl;
    }

    for(i = 0; i < len1; i++){
        if(arr1[i] != r_arr1[i]) break;
    }
    if(i == len1) cout << "Pass check point 4!" << endl;
    
    return 0;
}