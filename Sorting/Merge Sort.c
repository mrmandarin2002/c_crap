#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable : 6031)
#pragma warning (disable : 6011)
#pragma warning (disable : 6387)

#define DATA_SZ 4
#define MAXN 1000000

void print_array(int* arr_ptr, int N) {
	for (int x = 0; x < N; x++) {
		printf("%d ", *(arr_ptr + x));
	}
	printf("\n");
}

void merge_sort(int* arr_ptr, int length) {
	//printf("LENGTH: %d\n", length);
	if (length != 1) {
		int arr1_sz = length / 2;
		int arr2_sz = length - length / 2;
		int* arr1 = (int*)malloc(sizeof(int) * arr1_sz);
		memcpy(arr1, arr_ptr, arr1_sz * DATA_SZ);
		//printf("ARR1 first element: %d\n", *arr1);
		int* arr2 = (int*)malloc(sizeof(int) * arr2_sz);
		memcpy(arr2, arr_ptr + arr1_sz, arr2_sz * DATA_SZ);
		//printf("ARR2 first element: %d\n", *arr2);
		merge_sort(arr1, arr1_sz);
		merge_sort(arr2, arr2_sz);
		int cur_idx = 0, arr1_idx = 0, arr2_idx = 0;
		while (cur_idx < length) {
			if (arr1_idx < arr1_sz && (arr2_idx >= arr2_sz || *(arr1 + arr1_idx) < *(arr2 + arr2_idx))) {
				*(arr_ptr + cur_idx) = *(arr1 + arr1_idx);
				arr1_idx++;
			}
			else {
				*(arr_ptr + cur_idx) = *(arr2 + arr2_idx);
				arr2_idx++;
			}
			cur_idx++;
		}
		//print_array(arr_ptr, length);
		free(arr1);
		free(arr2);
	}
}

void main() {
	int N;
	scanf_s("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int x = 0; x < N; x++) {
		scanf_s("%d", &*(arr + x));
	}
	merge_sort(arr, N);
	print_array(arr, N);
}