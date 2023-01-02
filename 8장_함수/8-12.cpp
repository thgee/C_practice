//8-12

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_line(int x, int y, int z);

int main() {

	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		print_line(N - i,2 * i - 1 ,N - i);
		printf("\n");
	}

	return 0;
}

void print_line(int x, int y, int z) {
	for (int i = 0; i < x; i++) {
		printf(" ");
	}
	for (int i = 0; i < y; i++) {
		printf("*");
	}
	for (int i = 0; i < z; i++) {
		printf(" ");
	}
}
