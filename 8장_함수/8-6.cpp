// 8-6

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int func1(int x) {
	int res = 2 * x * x - 5 * x + 1;
	return res;
}

int main() {
	int x;
	scanf("%d", &x);
	printf("%d", func1(x));

	return 0;
}