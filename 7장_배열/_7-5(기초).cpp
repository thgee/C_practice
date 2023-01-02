// 7-5(±‚√ )

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printMax(int arr[]) {
	int max = arr[0];
	for (int i = 0; i < 10; i++)

		max = arr[i] > max ? arr[i] : max;

	printf("%d", max);
}

int main() {

	int x[10];

	for (int i = 0; i < 10; i++)
		scanf("%d", &x[i]);

	printMax(x);

	return 0;
}