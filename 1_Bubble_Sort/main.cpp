/* ===================================
 * 
 * Bubble Sort
 * 
 * =================================== */
#include <stdio.h>
using namespace std;

void swap(int *a, int *b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

void bubbleSort(int array_data[], int n_data) {
	int i, j;
	
	for (i = 0; i < n_data-1; i++)
		for (j = 0; j < n_data-i-1; j++)
			if (array_data[j] > array_data[j+1])
				swap( &array_data[j], &array_data[j+1] );
}

void printArray(int array_data[], int n_data) {
	int i;
	for (i = 0; i < n_data; i++)
		printf(" %i \t", array_data[i]);
	printf("\n");
}

int main() {
	// array data yang akan diurutkan
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Random array: \n");
	printArray(arr, n);
	
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	
	return 0;
}

// end of file main.cpp
