/*******************************************************************************
* FileName:         Huffman.cpp
* Author:           super
* Student Number:   0000000000
* Date:             2020/04/08 14:25:55
* Version:          v1.0
* Description:      Data Structure Experiment #9
*******************************************************************************/

#include "Huffman.h"
#include <cstring>
#include <string>
#include <algorithm>

HuffmanTree::HuffmanTree(const char* str){
    int size;// leaves
    char* ch = new char[strlen(str)];// dataes
    int* weigh = new int[strlen(str)];// weights
    size = 0;
    ch[0] = str[0];

    // reading dataes
    for (int i = 1; i < strlen(str); i++) {
        bool exist = false;
        for (int j = 0; j < size + 1; j++) {
            if (str[i] == ch[j])
                exist = true;
        }
        if (!exist)
            ch[++size] = str[i];
    }
    leaves = size + 1;
    nodes = 2 * leaves - 1;

    // reading weights
    for (int i = 0; i < leaves; i++) {
        weigh[i] = 0;
        for (int j = 0; j < strlen(str); j++) {
            if (ch[i] == str[j])
                weigh[i]++;
        }
    }

    // initializing
    HufTree = new HTNode[nodes];
    encode = new char[nodes];
    for (int i = 0; i < nodes; i++) {
        HufTree[i].weight = 0;
        HufTree[i].parent = -1;
        HufTree[i].lChild = -1;
        HufTree[i].rChild = -1;
        if (i < leaves) {
            HufTree[i].data = ch[i];
            HufTree[i].weight = weigh[i];
            HufTree[i].code = "";
        }
    }

    // combining
    // delete before
    for (int i = leaves; i < nodes; i++) {
        int min1, min2;
        mini(min1, min2);
        HufTree[min1].parent = i;
        HufTree[min2].parent = i;
        HufTree[i].lChild = min1;
        HufTree[i].rChild = min2;
        HufTree[i].weight = HufTree[min1].weight + HufTree[min2].weight;
        HufTree[min1].weight = -HufTree[min1].weight;
        HufTree[min2].weight = -HufTree[min2].weight;
    }

    // encoding
    // index change
    for (int i = 0; i < leaves; i++) {
        int parent_index = HufTree[i].parent;
        int child_index = i;
        while (parent_index != -1) {
            if (child_index == HufTree[parent_index].lChild)
                HufTree[i].code += "0";
            else if (child_index == HufTree[parent_index].rChild)
                HufTree[i].code += "1";
            child_index = parent_index;
            parent_index = HufTree[parent_index].parent;
        }
        reverse(HufTree[i].code.begin(), HufTree[i].code.end());
    }

    // freeing
    delete[] ch;
    delete[] weigh;
}

// searching for two minimums
void HuffmanTree::mini(int& left, int& right) {
    int min, _min;
    for (int i = 0; i < nodes; i++) {
        if (HufTree[i].weight > 0) {
            min = _min = HufTree[i].weight;
            left = right = i;
            break;
        }
    }

    for (int i = 0; i < nodes; i++) {
        if (HufTree[i].weight < min && HufTree[i].weight > 0) {
            min = HufTree[i].weight;
            left = i;
        }
    }

    for (int i = 0; i < nodes; i++) {
        if (HufTree[i].weight < _min && HufTree[i].weight > min && HufTree[i].weight > 0) {
            _min = HufTree[i].weight;
            right = i;
        }
    }
}

HuffmanTree::~HuffmanTree(){
    delete[] HufTree;
    delete[] encode;
}

char* HuffmanTree::getcode(char c){
    for (int i = 0; i < leaves; i++) {
        if (HufTree[i].data == c) {
            for (int j = 0; j < HufTree[i].code.length(); j++)
                encode[j] = HufTree[i].code[j];
            encode[HufTree[i].code.length()] = '\0';

            return encode;
        }
    }
    return NULL;
}

int HuffmanTree::getWPL(){
    int WPL;
    WPL = 0;

    for (int i = 0; i < leaves; i++)
        WPL += -HufTree[i].weight * HufTree[i].code.length();

    return WPL;
}