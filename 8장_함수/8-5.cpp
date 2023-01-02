// 8-5

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_triangle(int x) {
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

int main() {

	while (1) {

		int N;
		scanf("%d", &N);
		print_triangle(N);
		if (N <= 0) break;
	}

	return 0;
}