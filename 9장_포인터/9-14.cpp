// 9-14

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add_to_k(int* x, int* y);

int main() {

	int N;
	scanf("%d", &N);
	int arr[100];
	for (int* p = arr; p < arr + N; p++)
		scanf("%d", p);

	int sum = 0;

	for (int* p = arr; p < arr + N; p++)
		sum += add_to_k(arr, p);
	printf("%d", sum);
	return 0;
}

int add_to_k(int* x, int* y) {
	int sum = 0;
	for (int* p = x; p <= y; p++)
		sum += *p;
	return sum;
}

