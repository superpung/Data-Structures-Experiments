#include "SeqQueue.h"



SeqQueue::SeqQueue(){
    SeqList = new int[MAX_ELEMENTS];
    rear = fore = 0;
}
SeqQueue::~SeqQueue(){
    delete[] SeqList;
}
void SeqQueue::pop_front(){
    if (rear == 0)
        return;
    fore++; // don't need delete!
}
void SeqQueue::push_back(int data){
    if (rear > MAX_ELEMENTS - 1)
        return;
    SeqList[rear] = data;
    rear++;
}
int SeqQueue::front() const{
    if (rear == 0)
        return 0;
    return SeqList[fore];
}