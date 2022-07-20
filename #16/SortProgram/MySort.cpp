/*******************************************************************************
* FileName:         MySort.cpp
* Author:           super
* Student Number:   0000000000
* Date:             2019/05/27 13:56:55
* Version:          v1.0
* Description:      Data Structure Experiment #16
*******************************************************************************/

#include "MySort.h"

void MySort::bubbleSort(int* arr, int len){
    for (int i = 0, exchange = 1; i < len && exchange; i++) {
        exchange = 0;
        for (int j = 0; j < len - i; j++) {
            if (arr[j - 1] > arr[j]) {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                exchange = 1;
            }
        }
    }
}

void MySort::quickSort(int* arr, int len){
    qSort(arr, 0, len - 1);
}

void MySort::qSort(int* arr, int low, int high) {
    if (low < high) {
        int i = low;
        int j = high;
        int key = arr[low];
        while (i < j) {
            while (i < j && arr[j] >= key)
                j--;
            if (i < j)
                arr[i++] = arr[j];
            while (i < j && arr[i] <= key)
                i++;
            if (i < j)
                arr[j--] = arr[i];
        }
        arr[i] = key;
        qSort(arr, low, i - 1);
        qSort(arr, i + 1, high);
    }
}

void MySort::heapAdjust(int* arr, int s, int size) {
    int temp = arr[s];
    for (int i = 2 * s + 1; i < size; i = 2 * i + 1) {
        if (i < size - 1 && arr[i] < arr[i + 1])
            i++;
        if (temp >= arr[i])
            break;
        arr[s] = arr[i];
        s = i;
    }
    arr[s] = temp;
}

void MySort::heapSort(int* arr, int len){
    for (int i = len / 2 - 1; i >= 0; i--)
        heapAdjust(arr, i, len);
    for (int i = len - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapAdjust(arr, 0, i);
    }
}