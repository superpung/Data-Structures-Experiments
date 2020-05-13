#include <iostream>
#include <cstdio>

#include "Huffman.h"
using namespace std;

int main()
{
    HuffmanTree hf("aaaaaaaabbbbccd");

    if(strcmp(hf.getcode('a'), "1") == 0) cout << "pass check point 1!" << endl;
    if(strcmp(hf.getcode('b'), "01") == 0) cout << "pass check point 2!" << endl;
    if(strcmp(hf.getcode('c'), "001") == 0) cout << "pass check point 3!" << endl;
    if(strcmp(hf.getcode('d'), "000") == 0) cout << "pass check point 4!" << endl;
    
    if(hf.getWPL() == 25) cout << "pass check point 5!" << endl;

    return 0;
}