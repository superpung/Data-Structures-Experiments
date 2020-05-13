#include "LinkQueue.h"
#include <iostream>

LinkQueue::LinkQueue(){
    fore = rear = NULL;
}

LinkQueue::~LinkQueue(){
    while (fore != NULL) /* Don't put it "fore != rear"!
    When the last element was popped, fore = fore->next(fore == NULL so != rear), 
    which means fore == rear->next!!! So when fore == NULL, rear has been deleted.*/{
        QueueNode* temp = fore;
        fore = fore->next;
        delete temp;
        temp = NULL;
    }
    // So there shouldn't put "delete rear".
    rear = NULL;
}

void LinkQueue::push_back(int data){
    QueueNode *newNode = new QueueNode;
    newNode->value = data;
    newNode->next = NULL;
    /* Must think over the situation where the queue is empty 
    and the fore should also be initialised when you choose the non-head queue.*/
    if (fore == NULL) {
        fore = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void LinkQueue::pop_front(){
    if (rear == NULL)
        return;
    QueueNode *temp = fore;
    fore =  fore->next;
    delete temp;
    temp = NULL;
}


int LinkQueue::front() const{
    return fore->value;
}