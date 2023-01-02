// 8-1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int x, int y) {
	return x + y;
}

int main() {

	int N;
	scanf("%d", &N);

	int sum = 0;
	for (int i = 1; i <= N; i++)
		sum = add(sum, i);

	printf("%d", sum);
	return 0;
}
