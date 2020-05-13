/*******************************************************************************
* FileName:         SeqStack.h
* Author:           李晓鹏
* Student Number:   3019244114
* Date:             2020/03/11 13:41:55
* Version:          v1.0
* Description:      Data Structure Experiment #5
*                   待完成的SeqQueue.h文件
*******************************************************************************/

#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#include "MyQueue.h"

class SeqQueue: public MyQueue{
private:
    int rear, fore;
    int* SeqList;
    const static int MAX_ELEMENTS = 100;
public:
    SeqQueue();
    virtual ~SeqQueue();
    void pop_front();
    void push_back(int data);
    int front() const;
};
#endif