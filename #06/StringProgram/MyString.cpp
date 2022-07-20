/*******************************************************************************
* FileName:         MyString.cpp
* Author:           super
* Student Number:   0000000000
* Date:             2020/03/18 13:50:51
* Version:          v1.0
* Description:      Data Structure Experiment #6
*                   完成程度：
*                       简要说一下自己写了多少，完成了哪些函数
*******************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "MyString.h"


MyString::MyString(const char* str){
    len = strlen(str);
    myStr = new char[len + 1];
    strcpy(myStr, str);
    myStr[len] = '\0';
}

MyString::~MyString(){
    if (myStr) {
        delete[] myStr;
        myStr = NULL;
    }
    len = 0;
}

int MyString::length() const{
    return len;
}

void MyString::replace(const char* rep, int loc){
    int rLen = strlen(rep);
    if ((loc + rLen) > len) {
        myStr = (char*)realloc(myStr, loc + rLen + 1);
    }
    for (int i = loc; i < loc + rLen; i++)
        myStr[i] = rep[i - loc];
    myStr[loc + rLen] = '\0';

    len = loc + rLen;
}

int MyString::find(const char* str) const{
    // getNext
    int next[strlen(str)];
    next[0] = -1;
    int i = 0, j = -1;

    while (i < strlen(str)) {
        if (j == -1 || str[i] == str[j]) {
            i++;
            j++;
            next[i] = j;
        } else
            j = next[j];
    }

    // compare
    i = 0;
    j = 0;
    while (i < len && (j == -1 || j < strlen(str))) {
        if (j == -1 || myStr[i] == str[j]) {
            i++;
            j++;
        } else
            j = next[j];
    }
    if (j == strlen(str))
        return i - j;
    else
        return -1;
}

const char* MyString::c_string() const{
    return myStr;
}