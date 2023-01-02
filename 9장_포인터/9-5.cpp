// 9-5

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int arr[5];
	int rank[5] = { 0 };
	int* p, *q;
	int* r = rank;

	for (p = arr; p < arr + 5; p++) {
		scanf("%d", p);
	}

	for (p = arr; p < arr + 5; p++, r++) {
		for (q = arr; q < arr + 5; q++) {
			if (*p < *q) (*r)++;
		}
		printf("%d=r%d ", *p, *r + 1);
	}


	return 0;
}
