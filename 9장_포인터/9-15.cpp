// 9-15

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ABC(int *s, int k);

int main() {

	int arr[10];
	for (int *p = arr; p < arr + 10; p++)
		scanf("%d", p);

	int k = 9;
	for (int* p = arr; p < arr + 9; p++, k--){
		ABC(p, k);
	}

	for (int* p = arr; p < arr + 10; p++)
		printf(" %d", *p);


	return 0;
}

void ABC(int* s, int k) {
	int* pmax = s;
	for (int* p = s; p <= s + k; p++) {
		if (*pmax < *p) {
			pmax = p;
		}
	}
	int tmp = *s;
	*s = *pmax;
	*pmax = tmp;
}
