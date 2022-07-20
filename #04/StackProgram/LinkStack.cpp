/*******************************************************************************
* FileName:         LinkStack.cpp
* Author:           super
* Student Number:   0000000000
* Date:             2020/03/05 14:20:06
* Version:          v1.0
* Description:      Data Structure Experiment #4
*******************************************************************************/


#include "LinkStack.h"
#include <iostream>


LinkStack::LinkStack(){
    head = NULL;
    length = 0;
}

LinkStack::~LinkStack(){
    for (int i = 0; i < length; i++) {
        StackNode *temp;
        temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
    }
    delete head;
    head = NULL;
}

void LinkStack::push_back(int data){
    StackNode *newNode = new StackNode;
    newNode->value = data;
    newNode->next = head;
    head = newNode;
    length++;
}

int LinkStack::top() const{
    if (length == 0)
        return 0;
    else
        return head->value;
}

void LinkStack::pop(){
    if (length == 0)
        return;
    else {
        StackNode *temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
        length--;
    }
}
