// 8-7

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int func2(int x, int a, int b, int c) {
	int res = a * x * x + b * x + c;
	return res;
}

int main() {

	int x, a, b, c;
	scanf("%d%d%d%d", &x, &a, &b, &c);
	printf("%d", func2(x, a, b, c));

	return 0;
}