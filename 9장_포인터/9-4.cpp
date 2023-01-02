// 9-4

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int arr[3];
	int* p, *q;
	int temp;
	for (p = arr; p < arr + 3; p++) {
		scanf("%d", p);
	}
	
	for (p = arr; p < arr + 3; p++) {
		for (q = arr; q < arr + 3; q++) {
			if (*p > *q) {
				temp = *p;
				*p = *q;
				*q = temp;
			}
		}
	}

	printf("%d", *(arr + 1));

	return 0;
}
