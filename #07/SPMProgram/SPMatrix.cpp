/*******************************************************************************
* FileName:         SPMatrix.cpp
* Author:           super
* Student Number:   0000000000
* Date:             2020/03/25 13:59:58
* Version:          v1.0
* Description:      Data Structure Experiment #7
*
*******************************************************************************/

#include "SPMatrix.h"
#include <iostream>
using namespace std;

SPMatrix::SPMatrix(int r, int c){
    data = new Triple[r * c];
    mu = r;
    nu = c;
    tu = 0;
}

SPMatrix::SPMatrix(int r, int c, int max_element){
    data = new Triple[max_element];
    mu = r;
    nu = c;
    tu = 0;
}

int SPMatrix::get(int i, int j)const{
    for (int k = 0; k < tu; k++) {
        if (data[k].row == i && data[k].col == j)
            return data[k].value;
    }
    return 0;
}

void SPMatrix::set(int i, int j, int val){
    data[tu].row = i;
    data[tu].col = j;
    data[tu].value = val;
    tu++;
}

void SPMatrix::rotate(){
    // swap the row and col of the matrix
    int temp = mu;
    mu = nu;
    nu = temp;

    // swap the row and col of each element
    for (int k = 0; k < tu; k++) {
        int temp = data[k].row;
        data[k].row = data[k].col;
        data[k].col = temp;
    }
}

SPMatrix SPMatrix::operator+(const SPMatrix& b){
    // mention i or j and add.tu or tu
    // addition result
    SPMatrix add(mu, nu);
    if (b.mu != mu || b.nu != nu)
        return add;
    add.mu = mu;
    add.nu = nu;
    add.tu = 0;

    // regard the matrix as an array and generate the result
    int i = 0, j = 0, aLoc, bLoc;
    while (i < tu && j < b.tu) {
        aLoc = data[i].row * nu + data[i].col;
        bLoc = b.data[j].row * b.nu + b.data[j].col;

        // b is ahead of a
        if (aLoc < bLoc) {
            add.data[add.tu].row = data[i].row;
            add.data[add.tu].col = data[i].col;
            add.data[add.tu].value = data[i].value;
            i++;
        }

        // a is ahead of b
        if (aLoc > bLoc) {
            add.data[add.tu].row = b.data[j].row;
            add.data[add.tu].col = b.data[j].col;
            add.data[add.tu].value = b.data[j].value;
            j++;
        }

        // a is the same with b
        if (aLoc == bLoc) {
            if (data[i].value + b.data[j].value) {
                add.data[add.tu].row = data[i].row;
                add.data[add.tu].col = data[i].col;
                add.data[add.tu].value = data[i].value + b.data[j].value;
                i++;
                j++;
            }
        }

        // tu of result added
        add.tu++;
    }

    // unequal between a and b
    while (i < tu) {
        add.data[add.tu].row = data[i].row;
        add.data[add.tu].col = data[i].col;
        add.data[add.tu].value = data[i].value;
        i++;
        add.tu++;
    }
    while (j < b.tu) {
        add.data[add.tu].row = b.data[j].row;
        add.data[add.tu].col = b.data[j].col;
        add.data[add.tu].value = b.data[j].value;
        j++;
        add.tu++;
    }

    return add;
}

SPMatrix SPMatrix::operator-(const SPMatrix& b){
    // subtraction result
    SPMatrix sub(mu, nu);
    if (b.mu != mu || b.nu != nu)
        return sub;
    sub.mu = mu;
    sub.nu = nu;
    sub.tu = 0;

    // regard the matrix as an array and generate the result
    int i = 0, j = 0, aLoc, bLoc;
    while (i < tu && j < b.tu) {
        aLoc = data[i].row * nu + data[i].col;
        bLoc = b.data[j].row * b.nu + b.data[j].col;

        // b is ahead of a
        if (aLoc < bLoc) {
            sub.data[sub.tu].row = data[i].row;
            sub.data[sub.tu].col = data[i].col;
            sub.data[sub.tu].value = data[i].value;
            i++;
        }

        // a is ahead of b
        if (aLoc > bLoc) {
            sub.data[sub.tu].row = b.data[j].row;
            sub.data[sub.tu].col = b.data[j].col;
            sub.data[sub.tu].value = - b.data[j].value;
            j++;
        }

        // a is the same with b
        if (aLoc == bLoc) {
            if (data[i].value - b.data[j].value) {
                sub.data[sub.tu].row = data[i].row;
                sub.data[sub.tu].col = data[i].col;
                sub.data[sub.tu].value = data[i].value - b.data[j].value;
                i++;
                j++;
            }
        }

        // tu of result subtracted
        sub.tu++;
    }

    // unequal between a and b
    while (i < tu) {
        sub.data[sub.tu].row = data[i].row;
        sub.data[sub.tu].col = data[i].col;
        sub.data[sub.tu].value = data[i].value;
        i++;
        sub.tu++;
    }
    while (j < b.tu) {
        sub.data[sub.tu].row = b.data[j].row;
        sub.data[sub.tu].col = b.data[j].col;
        sub.data[sub.tu].value = - b.data[j].value;
        j++;
        sub.tu++;
    }

    return sub;
}

SPMatrix SPMatrix::operator*(const SPMatrix& b){
    // multiplication result
    SPMatrix mul(mu, nu);
    if (b.mu != nu)
        return mul;

    // resort b.data
    int* tuOfEachBRow = new int[b.mu];
    int* firstIndexOfEachBRow = new int[b.mu + 1];// +1 for searching
    int* rowPOfResult = new int[b.nu];
    int aLoc, aRowLoc, aColLoc, bColLoc;

    // initialize
    for (int i = 0; i < b.mu; i++)
        tuOfEachBRow[i] = 0;
    for (int i = 0; i < b.tu; i++)
        tuOfEachBRow[b.data[i].row]++;
    firstIndexOfEachBRow[0] = 0;
    for (int i = 1; i < b.mu; i++)
        firstIndexOfEachBRow[i] = firstIndexOfEachBRow[i - 1] + tuOfEachBRow[i - 1];

    // generate result
    aLoc = 0;
    mul.tu = -1;
    while (aLoc < tu) {
        aRowLoc = data[aLoc].row;
        for (int i = 0; i < b.nu; i++)
            rowPOfResult[i] = 0;
        // search all elements of aRowLoc and generate rowOfResult
        while (aLoc < tu && data[aLoc].row == aRowLoc) {
            aColLoc = data[aLoc].col;
            for (int i = firstIndexOfEachBRow[aColLoc]; i < firstIndexOfEachBRow[aColLoc + 1]; i++) {
                bColLoc = b.data[i].col;
                rowPOfResult[bColLoc] += data[aLoc].value * b.data[i].value;
            }
            aLoc++;
        }
        // randomly place rowOfResult into result
        for (int i = 0; i < b.nu; i++) {
            if (rowPOfResult[i]) {
                mul.tu++;
                mul.data[mul.tu].row = aRowLoc;
                mul.data[mul.tu].value = rowPOfResult[i];
                mul.data[mul.tu].col = i;
            }
        }
    }

    // generate datafield of result
    mul.mu = mu;
    mul.nu = b.nu;
    mul.tu++;

    // free and return
    delete[] tuOfEachBRow;
    delete[] firstIndexOfEachBRow;
    delete[] rowPOfResult;
    return mul;
}

SPMatrix::~SPMatrix(){
    delete[] data;
}