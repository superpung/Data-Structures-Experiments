/*******************************************************************************
* FileName:         MySort.h
* Author:           super
* Student Number:   0000000000
* Date:             2020/06/03 13:42:55
* Version:          v1.0
* Description:      Data Structure Experiment #17
*******************************************************************************/


/**
 *  归并排序，要求对arr进行归并排序，数组长度为len
    @name mergeSort(int*, int);
    @param arg1  需要排序的数组
    @param arg2  数组的长度
    @return
*/
void mergeSort(int* arr, int len);

void merge(int* left, int leftCount, int* right, int rightCount, int* result);

/**
 *  基数排序，要求对arr进行基数排序，数组长度为len
    @name cardSort(int*, int);
    @param arg1  需要排序的数组
    @param arg2  数组的长度
    @return
*/
void cardSort(int* arr, int len);