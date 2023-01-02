//7-5 (2Â÷¿ø)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arrsum(int arr[], int S, int E);

int main() {

	int N, S, E;
	scanf("%d%d%d", &N, &S, &E);

	int arr[100];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%d" , arrsum(arr, S, E));

	return 0;
}


int arrsum(int arr[], int S, int E) {
	int sum = 0;
	for (int i = S; i <= E; i++)
		sum += arr[i];
	return sum;
}

