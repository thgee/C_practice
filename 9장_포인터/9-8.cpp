// 9-8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* x, int* y);

int main() {
	
	int N;
	scanf("%d", &N);
	int arr[50];
	for (int* p = arr; p < arr + N; p++)
		scanf("%d", p);

	int a, b;
	scanf("%d%d", &a, &b);

	swap(&arr[a], &arr[b]);

	for (int* p = arr; p < arr + N; p++)
		printf("%d ", *p);

	return 0;
}

void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

