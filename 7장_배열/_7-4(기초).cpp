// 7-4(����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x[10], y[10], z[10];

	for (int i = 0; i < 10; i++)
		scanf("%d", &x[i]);
	for (int i = 0; i < 10; i++)
		scanf("%d", &y[i]);

	for (int i = 0, j = 9; i < 10; i++, j--) {
		z[i] = x[i] + y[j];
		printf(" %d", z[i]);
	}

	return 0;
}