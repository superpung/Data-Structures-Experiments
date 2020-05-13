/*******************************************************************************
* FileName:         SeqStack.cpp
* Author:           李晓鹏
* Student Number:   3019244114
* Date:             2020/03/05 14:21:56
* Version:          v1.0
* Description:      Data Structure Experiment #4
*******************************************************************************/
#include "SeqStack.h"
#include <iostream>

SeqStack::SeqStack(){
    SeqList = new int[MAX_ELEMENTS];
    data_top = 0;
}

SeqStack::~SeqStack(){
    delete[] SeqList;
    SeqList = NULL;
}

void SeqStack::push_back(int data){
    if (data_top > MAX_ELEMENTS - 1)
        return;
    else {
        SeqList[data_top] = data;
        data_top++;
    }
}

int SeqStack::top() const{
    if (data_top == 0)
        return 0;
    else
        return SeqList[data_top - 1];
}

void SeqStack::pop(){
    if (data_top == 0)
        return;
    else
        data_top--;
}
