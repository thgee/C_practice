// 7-3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int arr[5];
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
			if (arr[i] < arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}

	printf("%d\n%d", arr[0], arr[1]);

	return 0;
}