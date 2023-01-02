// 7-10(±‚√ )

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	float arr[10], res[10];
	int idx = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%f", &arr[i]);
		if (arr[i] > 0) res[idx++] = arr[i];
	}

	for (float* p = res; p < res + idx; p++)
		printf(" %.1f", *p);

	

	return 0;
}