#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int, int);
int sub(int, int);
int multiply(int, int);

int main() {

	int x, y;
	scanf("%d%d", &x, &y);
	
	int (*handle[3]) (int a, int b) = { add, sub, multiply };
	for (int i = 0; i < 3; i++)
		printf("%d ", handle[i](x, y));
	return 0;
}

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}