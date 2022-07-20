/*******************************************************************************
* FileName:         LinkQueue.h
* Author:           super
* Student Number:   0000000000
* Date:             2020/03/11 13:41:55
* Version:          v1.0
* Description:      Data Structure Experiment #5
*                   需要完成的LinkQueue.h，
*******************************************************************************/

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include "MyQueue.h"

class LinkQueue: public MyQueue{
private:
    struct QueueNode{
        QueueNode* next;
        int value;
    };
    QueueNode* fore;
    QueueNode* rear;
public:
    LinkQueue();
    virtual ~LinkQueue();
    void push_back(int data);
    void pop_front();
    int front() const;
};

#endif
