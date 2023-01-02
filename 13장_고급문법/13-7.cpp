#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int x, int y);

void main() {

	int a;
	scanf("%d", &a);
	void* p = &a;
	printf("%d\n", *(int*)p);

	int x, y;
	scanf("%d%d", &x, &y);

	int (*fp)(int, int);
	fp = add;
	printf("%d", fp(x, y));
}

int add(int x, int y) {
	return x + y;
}
