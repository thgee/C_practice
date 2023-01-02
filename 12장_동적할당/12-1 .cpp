// 12-1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int N;
	scanf("%d", &N);
	int* p = (int*)malloc(N * sizeof(int));

	int sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
		sum += p[i];
	}

	free(p);

	printf("%d", sum);

	return 0;
}