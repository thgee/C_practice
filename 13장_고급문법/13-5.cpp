#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pswap(int** ppx, int** ppy);

int main() {

	int x, y;
	scanf("%d%d", &x, &y);
	int* px = &x;
	int* py = &y;
	
	pswap(&px, &py);
	printf("%d %d", *px, *py);

	return 0;
}

void pswap(int** ppx, int** ppy) {
	int* tmp;
	tmp = *ppx;
	*ppx = *ppy;
	*ppy = tmp;
}
