/*******************************************************************************
* FileName:         myHash.cpp
* Author:           super
* Student Number:   0000000000
* Date:             2020/05/20 14:00:55
* Version:          v1.0
* Description:      Data Structure Experiment #15
*******************************************************************************/

#include "myHash.h"
#include <iostream>
#define mod 997

MyHash::MyHash(int max_element){
    HashTable = new TableNode[mod - 1];
    for (int i = 0; i < mod - 1; i++)
        HashTable[i].head = NULL;
}

MyHash::~MyHash(){
    for (int i = 0; i < mod - 1; i++) {
        HashNode* p = HashTable[i].head;
        while (p) {
            HashNode* temp = p;
            p = p->next;
            delete temp;
        }
    }
    delete[] HashTable;
}

void MyHash::setvalue(int key, int value){
    HashNode* newNode = new HashNode;
    newNode->key = key;
    newNode->value = value;
    newNode->next = HashTable[key % mod].head;
    HashTable[key % mod].head = newNode;
}

int MyHash::getvalue(int key){
    HashNode* p = HashTable[key % mod].head;
    while (p) {
        if (p->key == key)
            return p->value;
        p = p->next;
    }
    return 0;
}