// 9-12
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void addArray(int* x, int* y, int* z, int N);

int main() {

	int N;
	scanf("%d", &N);
	int a[20], b[20];
	int res[20];

	for (int* p = a; p < a + N; p++)
		scanf("%d", p);
	
	for (int* p = b; p < b + N; p++)
		scanf("%d", p);

	addArray(a, b, res, N);

	for (int* p = res; p < res + N; p++)
		printf(" %d", *p);
	return 0;
}

void addArray(int* x, int* y, int* z, int N) {
	int* p = x;
	int* q = y + N - 1;
	for (p; p < x + N; p++, q--, z++)
		*z = *p + *q;
}
