// 9-13

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arrsum(int* s, int* e);

int main() {

	int N, S, E;
	int arr[100];
	scanf("%d%d%d", &N, &S, &E);

	for (int* p = arr; p < arr + N; p++)
		scanf("%d", p);

	int sum = arrsum(arr + S, arr + E);
	printf("%d", sum);

	return 0;
}

int arrsum(int* s, int* e) {
	int sum = 0;
	for (int* p = s; p <= e; p++)
		sum += *p;
	return sum;
}

