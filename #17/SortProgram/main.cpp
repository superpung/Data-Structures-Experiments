#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

#include "MySort.h"

void shuffle(int* arr, int len){
	srand(time(0));
	for(int i = 0; i < len; i++){
		int randn = rand() % len;
		std::swap(arr[i], arr[randn]);
	}
}

int main()
{
	int i;
	int len = 100;
	int res[100] = {0};
	int arr[100] = {0};


	for(int i = 1; i < len; i++){
		arr[i] = arr[i - 1] + rand() % 100;
		res[i] = arr[i];
	}

	shuffle(arr, len);
	mergeSort(arr, len);

	for(i = 0; i < len; i++){
		if(arr[i] != res[i]) break;
	}
	if(i == len) printf("Pass check point 1!\n");

	shuffle(arr, len);
	cardSort(arr, len);

	for(i = 0; i < len; i++){
		if(arr[i] != res[i]) break;
	}
	if(i == len) printf("Pass check point 2!\n");

    return 0;
}