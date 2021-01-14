#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable : 6031)
#pragma warning (disable : 6011)
#pragma warning (disable : 6387)

#define DATA_SZ 4

void print_array(int* arr_ptr, int N) {
	for (int x = 0; x < N; x++) {
		printf("%d ", *(arr_ptr + x));
	}
	printf("\n");
}

void swap(int* num1, int* num2) {
	int temp_num = *num1;
	*num1 = *num2;
	*num2 = temp_num;
}

//returns idx of pivot
int partition(int* arr_ptr, int L, int R) {
	int pivot = *(arr_ptr + R);
	//printf("PIVOT VALUE: %d\n", pivot);
	int pivot_idx = 0;
	for (int x = L; x < R; x++) {
		if (*(arr_ptr + x) <= pivot) {
			if (pivot_idx != x) {
				swap(arr_ptr + L + pivot_idx, arr_ptr + x);
			}
			pivot_idx += 1;
		}
	}
	swap(arr_ptr + L + pivot_idx, arr_ptr + R);
	return L + pivot_idx;
}

void quick_sort(int* arr_ptr, int L, int R) {
	//printf("LEFT RIGHT: %d %d\n", L, R);
	if (L < R) {
		int pivot_idx = partition(arr_ptr, L, R);
		//print_array(arr_ptr, 5);
		quick_sort(arr_ptr, L, pivot_idx - 1);
		quick_sort(arr_ptr, pivot_idx + 1, R);
	}
}

void main() {
	int N;
	scanf_s("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int x = 0; x < N; x++) {
		scanf_s("%d", &*(arr + x));
	}
	quick_sort(arr, 0, N - 1);
	print_array(arr, N);
}