#define _CRT_SECURE_NO_WARNINGS
#define a 10
#define ABS(x) ((x) >= 0? (x): -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#include <stdio.h>

int main() {

	/*int arr[6];
	for (int i = 0; i < 6; i++)
		scanf("%d", &arr[i]);*/
	int b = 10;
	printf("%d", b);

	//int max = arr[0];
	//int max_abs = ABS(arr[0]);
	//for (int i = 0; i < 6; i++) {
	//	int abs = ABS(arr[i]);
	//	if (MAX(max_abs, abs) > max_abs) {
	//		max = arr[i];
	//		max_abs = abs;
	//	}
	//}

	//printf("%d %d", max, max_abs);

	return 0;
}