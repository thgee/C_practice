// 7-8(����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int N, x[10];
	scanf("%d", &N);

	int idx = 0;
	while (N) {
		x[idx] = N % 10;
		N /= 10; // N �� �ڸ����� ����
		idx++;
	}

	for (int i = 0; i < idx; i++)
		printf(" %d", x[i]);

	return 0;
}