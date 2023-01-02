// 8-3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int n) {
	return n * (n + 1) / 2;
}

int main() {

	int N;
	int res = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		res += sum(i);
	printf("%d", res);

	return 0;
}