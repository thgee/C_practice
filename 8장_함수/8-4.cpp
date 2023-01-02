// 8-4

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_row1(int x) {
	for (int i = 0; i < x; i++) {
		printf("%d", x);
	}
}

void print_row2(int x) {
	printf("%d", x);
	for (int i = 0; i < x - 2; i++) {
		printf(" ");
	}
	printf("%d", x);
}

int main() {

	int N;
	scanf("%d", &N);

	print_row1(N);
	printf("\n");
	for (int i = 0; i < N - 2; i++) {
		print_row2(N);
		printf("\n");
	}
	print_row1(N);

	return 0;
}