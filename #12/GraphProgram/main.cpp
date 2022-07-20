#include <iostream>
#include <cstdio>

#include "Graph.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    // 1
    Graph g(5);

    g.addedge(1, 2, 10);
    g.addedge(1, 3, 10);
    g.addedge(1, 4, 10);
    g.addedge(1, 5, 10);
    g.addedge(2, 3, 1);
    g.addedge(3, 4, 1);
    g.addedge(4, 5, 1);

    int len = g.getV();
    int *arr = g.topological();

    int r_arr[5] = {1, 2, 3, 4, 5};
    
    if(len == 5){
        cout << "Pass check point 1!" << endl;
    }

    int i;
    for(i = 0; i < len; i++){
        if(arr[i] != r_arr[i]) break;
    }
    if(i == len) cout << "Pass check point 2!" << endl;

    // 2
    Graph g1(6);

    g1.addedge(1, 2, 10);
    g1.addedge(1, 4, 10);
    g1.addedge(2, 6, 10);
    g1.addedge(3, 2, 10);
    g1.addedge(3, 6, 1);
    g1.addedge(5, 1, 1);
    g1.addedge(5, 2, 1);
    g1.addedge(5, 6, 1);

    int len1 = g1.getV();
    int *arr1 = g1.topological();

    int r_arr1[6] = {5, 1, 4, 3, 2, 6};
    
    if(len1 == 6){
        cout << "Pass check point 3!" << endl;
    }

    int j;
    for(j = 0; j < len1; j++){
        if(arr1[j] != r_arr1[j]) break;
    }
    if(j == len1) cout << "Pass check point 4!" << endl;

    // 3
    Graph g2(5);

    g2.addedge(1, 2, 10);
    g2.addedge(1, 4, 10);
    g2.addedge(2, 4, 10);
    g2.addedge(3, 5, 10);
    g2.addedge(4, 3, 10);
    g2.addedge(4, 5, 10);
  
    int len2 = g2.getV();
    int *arr2 = g2.topological();

    int r_arr2[5] = {1, 2, 4, 3, 5};
    
    if(len2 == 5){
        cout << "Pass check point 5!" << endl;
    }

    int k;
    for(k = 0; k < len2; k++){
        if(arr2[k] != r_arr2[k]) break;
    }
    if(k == len2) cout << "Pass check point 6!" << endl;

    return 0;
}