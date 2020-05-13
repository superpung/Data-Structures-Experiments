#include <cstdio>
#include <iostream>

#include "DBLinkList.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	DBLinkList dlist;
	dlist.insert(22, 0);
	dlist.insert(35, 1);
	dlist.insert(12, 1);
	dlist.insert(51, 2);
	// 22 12 51 35

	if(dlist.getData(1) == 12) cout << "pass check point 1!" << endl;
	if(dlist.getData(3) == 35 && dlist.length() == 4) cout << "pass check point 2!" << endl;

	dlist.remove(2);
	// 22 12 35

	if(dlist.getData(0) == 22 && dlist.getData(1) == 12 && dlist.getData(2) == 35)
		cout << "pass check point 3!" << endl;


	if(dlist.length() == 3)
		cout << "pass check point 4!" << endl;

	dlist.bubbleSort();
	// 12 22 35

	if (dlist.getData(0) == 12 && dlist.getData(1) == 22 && dlist.getData(2) == 35)
		cout << "pass check point 5!" << endl;
	return 0;
}
