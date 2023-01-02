// 9-7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(int* x, int* y, int* z);
void output(int* x, int* y, int* z);

int main() {

	int x, y, z;
	input(&x, &y, &z);
	output(&x, &y, &z);

	return 0;
}

void input(int* x, int* y, int* z) {
	scanf("%d", x);
	scanf("%d", y);
	scanf("%d", z);
}

void output(int* x, int* y, int* z) {
	printf("%d %d %d", *x, *y, *z);
}
