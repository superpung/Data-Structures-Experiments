/*******************************************************************************
* FileName:         SeqList.cpp
* Author:           李晓鹏
* Student Number:   3019244114
* Date:             2020/02/19 22:39:41
* Version:          v1.0
* Description:      Data Structure Experiment #1
*                   作业在这个文件中完成，需要补全SeqList类的实现，
*                   给出了构造函数与析构函数的例子.
*                   写明必要的注释
*******************************************************************************/

#include "SeqList.h"

/*
    使用初始化列表来初始化const变量LIST_SIZE，
    并动态分配LIST_SIZE长度的数组。
*/
SeqList::SeqList(const int& listSize) :LIST_SIZE(listSize)
{
    seq = new int[LIST_SIZE];
    // equal to:  seq = (int*) malloc(sizeof(int) * LIST_SIZE);
    len = 0;
}

SeqList::~SeqList(){
    delete[] seq;
}

bool SeqList::isIn(const int& data){
    bool defaultOut = false;
    for (int i = 0; i < len; i++)
    {
        if (data == seq[i])
        {
            defaultOut = true;
            break;
        }
    }
        if (defaultOut)
            return true;
        else
            return false;
}

int SeqList::length(){
    return len;
}

int SeqList::getData(const int& location){
    return seq[location];
}

bool SeqList::insert(const int& data, const int& location){
    if (len == LIST_SIZE)
        return false;
    else
    {
        for (int i = len - 1; i >= location; i--)
            seq[i + 1] = seq[i];
        seq[location] = data;
        len++;
        return true;
    }
}

bool SeqList::remove(const int& location){
    if (location >= len || location < 0 || len == 0)
        return false;
    else
    {
        for (int i = location; i < len - 1; i++)
            seq[i] = seq[i + 1];
        len--;
        return true;
    }
}
