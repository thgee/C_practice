// 8-8

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int func2(int x, int a, int b, int c) {
	int res = a * x * x + b * x + c;
	return res;
}

int main() {

	int x;
	int a, b, c;
	int d, e, f;
	int tmp, res;

	scanf("%d%d%d%d", &x, &a, &b, &c);
	scanf("%d%d%d", &d, &e, &f);
	tmp = func2(x, a, b, c);
	res = func2(tmp, d, e, f);
	printf("%d", res);
	return 0;
}