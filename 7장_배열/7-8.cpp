// 7-8

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* x, int* y);

int main() {

	int arr[5];
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < 4; i++) {
		swap(&arr[i], &arr[i + 1]);
	}

	for (int i = 0; i < 5; i++)
		printf("%d\n", arr[i]);

	return 0;
}

void swap(int* x, int* y) {

	if (*x > *y) {
		int tmp = *x;
		*x = *y;
		*y = tmp;
	}
}