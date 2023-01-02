// 8-2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int n) {
	return n*(n+1) / 2;
}

int main() {

	int x, y;
	int res = 0;
	scanf("%d%d", &x, &y);
	res = sum(y) - sum(x - 1);
	printf("%d", res);

	return 0;
}
