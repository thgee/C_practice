// 7-8(기초)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int N, x[10];
	scanf("%d", &N);

	int idx = 0;
	while (N) {
		x[idx] = N % 10;
		N /= 10; // N 의 자리수를 낮춤
		idx++;
	}

	for (int i = 0; i < idx; i++)
		printf(" %d", x[i]);

	return 0;
}