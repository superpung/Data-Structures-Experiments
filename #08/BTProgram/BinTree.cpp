/*******************************************************************************
* FileName:         BinTree.cpp
* Author:           super
* Student Number:   0000000000
* Date:             2020/04/01 14:03:55
* Version:          v1.0
* Description:      Data Structure Experiment #8
*******************************************************************************/


#include "BinTree.h"
#include <iostream>

BinTree::BinTree(){
    root = NULL;
    count = 0;
}

BinTree::~BinTree(){
    destroyTree(root);
}

void BinTree::destroyTree(BinNode* Tree) {
    while (Tree) {
        BinNode* left = Tree->lChild;
        BinNode* right = Tree->rChild;
        delete Tree;
        Tree = NULL;
        if (left)
            destroyTree(left);
        if (right)
            destroyTree(right);
    }
}

BinNode* BinTree::search_number(BinNode* Tree, int num) const {
    while (Tree) {
        if (Tree->number == num)
            return Tree;
        else {
            search_number(Tree->lChild, num);
            search_number(Tree->rChild, num);
        }
    }
    return NULL;
}

void BinTree::insert(int val, int parent, int flg) {
    BinNode* newNode = new BinNode;
    newNode->data = val;
    newNode->number = count + 1;
    newNode->lChild = newNode->rChild = NULL;
    if (parent == 0)
        root = newNode;
    else {
        if (flg == -1)
            search_number(root, parent)->lChild = newNode;
        else if (flg == 1)
            search_number(root, parent)->rChild = newNode;
    }
    count++;
}

int* BinTree::p_traversal() const {
    int* p = new int[count];
    int i = 0;
    p_order(root, p, i);
    return p;
}

// transmission by reference!!!
void BinTree::p_order(BinNode* Tree, int* &pointer, int &index) const {
    if (Tree) {
        pointer[index++] = Tree->data;
        p_order(Tree->lChild, pointer, index);
        p_order(Tree->rChild, pointer, index);
    }
}

int* BinTree::m_traversal() const {
    int* p = new int[count];
    int i = 0;
    m_order(root, p, i);
    return p;
}

// transmission by reference!!!
void BinTree::m_order(BinNode* Tree, int* &pointer, int &index) const {
    if (Tree) {
        m_order(Tree->lChild, pointer, index);
        pointer[index++] = Tree->data;
        m_order(Tree->rChild, pointer, index);
    }
}

int BinTree::countNode() const {
    return count;
}

int BinTree::height() const {
    return getHeight(root);
}

int BinTree::getHeight(BinNode* Tree) const {
    if (Tree == NULL)
        return 0;
    else {
        int m = getHeight(Tree->lChild);
        int n = getHeight(Tree->rChild);
        return (m > n) ? m + 1 : n + 1;
    }
}