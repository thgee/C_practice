// 9-9
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int* mid(int arr[]);

int main() {

	int arr[3];
	for (int* p = arr; p < arr + 3; p++)
		scanf("%d", p);
	printf("%d", *mid(arr));
	return 0;
}

int* mid(int arr[]) {
	int* res = NULL;
	int x = *arr;
	int y = *(arr + 1);
	int z = *(arr + 2);
	if ((x >= y && x <= z) || (x >= z && x <= y)) res = arr;
	if ((y >= z && y <= x) || (y >= x && y <= z)) res = arr + 1;
	if ((z >= x && z <= y) || (z >= y && z <= x)) res = arr + 2;
	return res;
}

