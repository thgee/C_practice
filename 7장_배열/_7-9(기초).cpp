// 7-9(±‚√ )

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int N, res = 0;
	int arr[10];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++) {
		res *= 10;
		res += arr[i];
	}

	printf("%d", res);


	return 0;
}