// 9-10
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void gcdlcm(int x, int y, int* gcd, int* lcm);

int main() {

	int x, y;
	scanf("%d%d", &x, &y);
	int gcd, lcm;
	gcdlcm(x, y, &gcd, &lcm);
	printf("%d %d", gcd, lcm);


	return 0;
}

void gcdlcm(int x, int y, int* gcd, int* lcm) {

	int min = x > y ? y : x;
	*gcd = 1;
	for (int i = 1; i <= min; i++) {
		if (x % i == 0 && y % i == 0) *gcd = i;
	}

	*lcm = x * y / *gcd;
}
