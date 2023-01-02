// 7-1 (2Â÷¿ø)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int arr[3][3];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &arr[i][j]);

	int tr = 0;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (i == j) tr += arr[i][j];

	printf("%d", tr);

	return 0;
}