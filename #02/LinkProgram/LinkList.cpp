/*******************************************************************************
* FileName:         LinkList.cpp
* Author:           super
* Student Number:   0000000000
* Date:             2020/02/26 14:00:49
* Version:          v1.0
* Description:      Data Structure Experiment #2
*                   作业在这个文件中完成，需要补全LinkList类的实现，
*                   写明必要的注释
*******************************************************************************/

#include "LinkList.h"
#include <iostream>

LinkList::LinkList(){
    head = NULL;
    len = 0;
}

LinkList::~LinkList(){
    for (int i = 0; i < len; i++) {
        node *temp;
        temp = head;
        head = head->next;
        delete temp;
    }
    delete head;
}

int LinkList::length()
{
    return len;
}

int LinkList::getData(const int &location)
{
    node *p = head;
    for (int i = 0; i < location; i++)
        p = p->next;
    return p->value;
}

void LinkList::insert(const int& data, const int& location){
    node *newNode = (node*) malloc(sizeof(node));
    newNode->value = data;
    if (head == NULL || location == 0) {
        newNode->next = head;
        head = newNode;
        len++;
    } else {
    node *p = head;
    for (int i = 0; i < location - 1; i++)
        p = p->next;
    newNode->next = p->next;
    p->next = newNode;
    len++;
    }
}

bool LinkList::remove(const int& location){
    if (location == 0) {
        node *temp = head;
        head = head->next;

        delete temp;
        temp = NULL;
        len--;
        return true;
    }
    else
    {
        node *p = head;
        for (int i = 0; i < location - 1; i++)
            p = p->next;
        if (p == NULL || p->next == NULL)
            return false;
        node *temp = p->next;
        p->next = temp->next;
        len--;
        free(temp);
        return true;
    }
}

void LinkList::converse(){
    for (int i = 0; i < len / 2; i++) {
        node *p = head;
        for (int j = 0; j < i; j++)
            p = p->next;
        node *q = head;
        for (int j = 0; j < len - i - 1; j++)
            q = q->next;
        int temp = p->value;
        p->value = q->value;
        q->value = temp;
    }
}

void LinkList::append(const LinkList& append_list){
    node *p = head;
    for (int i = 0; i < len - 1; i++)
        p = p->next;
    p->next = append_list.head;
    len += append_list.len;
}
