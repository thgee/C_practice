// 7-2 (2Â÷¿ø)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int arr[3][2];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			scanf("%d", &arr[i][j]);

	int grade[3] = { 0 };

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			grade[i] += arr[i][j];

	for (int i = 0; i < 3; i++)
		printf("%d\n", grade[i]);

	return 0;
}