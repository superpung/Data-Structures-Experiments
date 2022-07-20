#include <iostream>
#include <cstdio>

#include "Graph.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Graph g(5);

    g.addedge(1, 2, 10);
    g.addedge(1, 3, 10);
    g.addedge(1, 4, 10);
    g.addedge(1, 5, 10);
    g.addedge(2, 3, 1);

    if(g.prim() == 31) cout << "pass check point 1!" << endl;
    if(g.kruskal() == 31) cout << "pass check point 2!" << endl;

    Graph g1(7);

    g1.addedge(1, 2, 7);
    g1.addedge(1, 4, 5);
    g1.addedge(2, 3, 8);
    g1.addedge(2, 4, 9);
    g1.addedge(2, 5, 7);
    g1.addedge(3, 5, 5);
    g1.addedge(4, 5, 15);
    g1.addedge(4, 6, 6);
    g1.addedge(5, 6, 8);
    g1.addedge(5, 7, 9);
    g1.addedge(6, 7, 11);

    if(g1.prim() == 39) cout << "pass check point 3!" << endl;
    if(g1.kruskal() == 39) cout << "pass check point 4!" << endl;

    Graph g2(6);

    g2.addedge(1, 2, 6);
    g2.addedge(1, 3, 1);
    g2.addedge(1, 4, 5);
    g2.addedge(2, 3, 5);
    g2.addedge(2, 5, 3);
    g2.addedge(3, 4, 5);
    g2.addedge(3, 5, 6);
    g2.addedge(3, 6, 4);
    g2.addedge(4, 6, 2);
    g2.addedge(5, 6, 6);

    if(g2.prim() == 15) cout << "pass check point 5!" << endl;
    if(g2.kruskal() == 15) cout << "pass check point 6!" << endl;

    Graph g3(10);

    g3.addedge(1, 2, 3);
    g3.addedge(1, 4, 6);
    g3.addedge(1, 5, 9);
    g3.addedge(2, 3, 2);
    g3.addedge(2, 4, 4);
    g3.addedge(2, 6, 9);
    g3.addedge(3, 4, 2);
    g3.addedge(3, 6, 8);
    g3.addedge(3, 7, 9);
    g3.addedge(4, 7, 9);
    g3.addedge(5, 6, 8);
    g3.addedge(5, 10, 18);
    g3.addedge(6, 7, 7);
    g3.addedge(6, 9, 9);
    g3.addedge(6, 10, 10);
    g3.addedge(7, 8, 4);
    g3.addedge(7, 9, 5);
    g3.addedge(8, 9, 1);
    g3.addedge(8, 10, 4);
    g3.addedge(9, 10, 3);

    if(g3.prim() == 38) cout << "pass check point 7!" << endl;
    if(g3.kruskal() == 38) cout << "pass check point 8!" << endl;

    return 0;
}