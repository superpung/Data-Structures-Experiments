/*******************************************************************************
* FileName:         DBLinkList.cpp
* Author:           super
* Student Number:   0000000000
* Date:             2020/03/04 13:56:45
* Version:          v1.0
* Description:      Data Structure Experiment #3
*******************************************************************************/

#include "DBLinkList.h"
#include <iostream>

DBLinkList::DBLinkList(){
    head = NULL;
    tail = NULL;
    len = 0;
}
DBLinkList::~DBLinkList(){
    for (int i = 0; i < len; i++) {
        DBNode *temp;
        temp = head;
        head = head->nxt;
        delete temp;
    }
    delete head;
    head = NULL;
    delete tail;
    tail = NULL;
}

void DBLinkList::insert(int data, int location){
    if (location < 0 || location > len)
        return;

    DBNode *newNode = new DBNode;
    newNode->value = data;
    if (location == 0) {
        newNode->nxt = head;
        newNode->pre = NULL;
        head = newNode;
        if (tail == NULL) {
            tail = newNode;
            newNode->nxt = NULL;
        } else
            newNode->nxt->pre = newNode;
    }

    else if (location != len) {
    DBNode *p = head;
    for (int i = 0; i < location - 1; i++)
        p = p->nxt;
    p->nxt->pre = newNode;
    newNode->nxt = p->nxt;
    p->nxt = newNode;
    newNode->pre = p;
    }

    else if (location == len) {
        tail->nxt = newNode;
        newNode->pre = tail;
        tail = newNode;
        newNode->nxt = NULL;
    }

    len++;
}

void DBLinkList::remove(int location){
    if (location == 0) {
        if (len == 1) {
            DBNode *temp = head;
            head = NULL;
            tail = NULL;

            delete temp;
            temp = NULL;
        }
        else
        {
            head->nxt->pre = NULL;
            DBNode *temp = head;
            head = head->nxt;

            delete temp;
            temp = NULL;
        }
    }

    else if (location != len - 1) {
        DBNode *p = head;
        for (int i = 0; i < location; i++)
            p = p->nxt;
        p->pre->nxt = p->nxt;
        p->nxt->pre = p->pre;

        delete p;
        p = NULL;
    }

    else if (location == len - 1) {
        DBNode *temp = tail;
        tail = tail->pre;
        tail->nxt = NULL;

        delete temp;
        temp = NULL;
    }

    len--;
}

int DBLinkList::length(){
    return len;
}

int DBLinkList::getData(int location){
    DBNode *p = head;
    for (int i = 0; i < location; i++)
        p = p->nxt;
    return p->value;
}

void DBLinkList::bubbleSort(){
    for (int i = 0; i < len - 1; i++) {
        DBNode *p = head;
        for (int j = 0; j < len - i - 1; j++)
        {
            p = p->nxt;
            if (p->pre->value > p->value) {
                int temp = p->pre->value;
                p->pre->value = p->value;
                p->value = temp;
            }
        }
    }
}
