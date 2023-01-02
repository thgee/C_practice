#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int GCF(int a, int b);

int main() {

	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", GCF(a, b));
	return 0;
}

int GCF(int a, int b) {
	
	int max = a > b ? a : b;
	int min = a > b ? b : a;
	if (max % min == 0) return min;
	else return GCF(max % min, min);
	printf("1");
}
