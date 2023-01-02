// 7-1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int arr[5];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	float avg = sum / 5.0f;
	for (int i = 0; i < 5; i++) {
		if (arr[i] > avg) printf("%d\n", arr[i]);
	}


	return 0;
}