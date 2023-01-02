// 12-2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int N;
	scanf("%d", &N);
	float* p = (float*)malloc(N * sizeof(float));

	for (int i = 0; i < N; i++) {
		scanf("%f", &p[i]);
	}

	float max = p[0];
	for (int i = 0; i < N; i++) {
		if (max < p[i]) {
			max = p[i];
		}
	}
	printf("%.2f", max);


	return 0;
}