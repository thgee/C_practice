// 7-11(±‚√ )

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printMin(float[], int);

int main() {

	float arr[10];
	for (int i = 0; i < 10; i++)
		scanf("%f", &arr[i]);

	int len = sizeof(arr) / sizeof(float);
	printMin(arr, len);


	return 0;
}

void printMin(float arr[], int len) {
	float min = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] < min) min = arr[i];
	}
	printf("%.1f", min);
}
