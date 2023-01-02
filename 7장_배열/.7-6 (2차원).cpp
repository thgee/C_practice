//7-6 (2Â÷¿ø)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void prt(int arr[][5], int N);

int main() {

	int N;
	scanf("%d", &N);
	int arr[20][5];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &arr[i][j]);

	prt(arr, N);

	return 0;
}

void prt(int arr[][5], int N) {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}


