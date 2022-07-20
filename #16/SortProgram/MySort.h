/*******************************************************************************
* FileName:         MySort.h
* Author:           super
* Student Number:   0000000000
* Date:             2020/05/27 13:56:55
* Version:          v1.0
* Description:      Data Structure Experiment #16
*******************************************************************************/

class MySort{
private:
    MySort(){}
    static void qSort(int* arr, int low, int high);
    static void heapAdjust(int* arr, int s, int m);
public:
    ~MySort(){}

    /**
     *  冒泡排序，要求对arr进行冒泡排序，数组长度为len
        @name bubbleSort(int*, int);
        @param arg1  需要排序对数组
        @param arg2  数组的长度
        @return
    */
    static void bubbleSort(int* arr, int len);

    /**
     *  快速排序，对arr进行快速排序，数组长度为len
        @name quickSort(int*, int);
        @param arg1  需要排序对数组
        @param arg2  数组的长度
        @return
    */
    static void quickSort(int* arr, int len);

    /**
     *  堆排序，要求对arr进行堆排序，数组长度为len
        @name heapSort(int*, int);
        @param arg1  需要排序对数组
        @param arg2  数组的长度
        @return
    */
    static void heapSort(int* arr, int len);
};