/*******************************************************************************
* FileName:         MySort.cpp
* Author:           super
* Student Number:   0000000000
* Date:             2019/06/03 13:42:55
* Version:          v1.0
* Description:      Data Structure Experiment #17
*******************************************************************************/

#include "MySort.h"
#include <iostream>

void merge(int* leftArr, int leftCount, int* rightArr, int rightCount, int* resultArr) {
    int i = 0, j = 0, k = 0;
    // choose the smaller
    while (i < leftCount && j < rightCount) {
        if (leftArr[i] < rightArr[j])
            resultArr[k++] = leftArr[i++];
        else
            resultArr[k++] = rightArr[j++];
    }
    // one of follows
    while (i < leftCount)
        resultArr[k++] = leftArr[i++];
    while (j < rightCount)
        resultArr[k++] = rightArr[j++]; // right!!!
}

void mergeSort(int *arr, int len){
    if (len < 2)
        return;
    int mid = len / 2;
    int* leftArr = new int[mid];
    int* rightArr = new int[len - mid];
    int i;

    for (i = 0; i < mid; i++)
        leftArr[i] = arr[i];
    for (i = 0; i < len - mid; i++)
        rightArr[i] = arr[i + mid];

    mergeSort(leftArr, mid);
    mergeSort(rightArr, len - mid);

    merge(leftArr, mid, rightArr, len - mid, arr);

    delete[] leftArr;
    delete[] rightArr;
}

void cardSort(int* arr, int len){
    int maxBitsCount = 1, curBitsCount; // max number of digits
    int curNum, curBit; // current number and digit
    int highDigits, lowestDigit; // high digits and its lowest of number
    int digitEndPos[10]; // different digits' end position
    int resultArr[len]; // sort result
    int i, j;
    // search for max number
    for (int i = 0; i < len; i++) {
        curNum = arr[i];
        curBitsCount = 0;
        while (curNum) {
            curBitsCount++;
            curNum /= 10;
        }
        maxBitsCount = (curBitsCount > maxBitsCount) ? curBitsCount : maxBitsCount;
    }
    // sort
    for (i = 0, curBit = 1; i < maxBitsCount; i++, curBit *= 10) {
        // init
        for (j = 0; j < 10; j++)
            digitEndPos[j] = 0;
        for (j = 0; j < len; j++) {
            highDigits = arr[j] / curBit;
            lowestDigit = highDigits % 10;
            digitEndPos[lowestDigit]++;
        }
        // locate
        digitEndPos[0]--; // from 0
        for (j = 1; j < 10; j++)
            digitEndPos[j] += digitEndPos[j - 1];
        // move
        for (j = len - 1; j >= 0; j--) {
            highDigits = arr[j] / curBit;
            lowestDigit = highDigits % 10;
            resultArr[digitEndPos[lowestDigit]--] = arr[j];
        }
        // copy
        for (j = 0; j < len; j++)
            arr[j] = resultArr[j];
    }
}