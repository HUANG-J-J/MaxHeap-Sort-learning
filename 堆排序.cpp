#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define length 10

void InitARR(int*& arr, int len) {
	arr = (int*)calloc(len, sizeof(int));

	for (int i = 0; i < len; i++) {
		if (arr)
			arr[i] = rand() % 100;
	}
}

void PrintARR(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
}

void swap(int& a, int& b) {
	int flag = a;
	a = b;
	b = flag;
}

void MaxHeapAdjust(int *arr,int key,int len) {
	int dad = key;
	int son = 2 * dad + 1;
	while (son<len) {
		if (son + 1 < len && arr[son] < arr[son + 1]) {
			son++;
		}
		if (arr[son] > arr[dad]) {
			swap(arr[son], arr[dad]);
			dad = son;
			son = 2 * dad + 1;
		}
		else {
			break;
		}
	}
}

void MaxHeapSort(int* arr, int len) {
	for (int i = len / 2 - 1; i >= 0; i--) {
		MaxHeapAdjust(arr, i, len);
	}
	swap(arr[0], arr[len - 1]);
	for (int i = len - 1; i > 1; i--) {
		MaxHeapAdjust(arr, 0, i);
		swap(arr[0], arr[i - 1]);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int *ARR=NULL;
	int i = 0;
	InitARR(ARR, length);
	PrintARR(ARR, length);
	printf("\n\n---------MaxHeapSort---------\n\n");
	MaxHeapSort(ARR, length);
	PrintARR(ARR, length);

	return 0;
}
