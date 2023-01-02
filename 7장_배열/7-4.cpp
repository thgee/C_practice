// 7-4

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int arr[10], cnt[3] = { 0 };

	for (int i = 0; i < 10; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 10; j++)
			if (arr[j] == i + 1) cnt[i]++;

	for (int i = 1; i <= 3; i++) {
		printf("%d:", i);
		for (int j = 0; j < cnt[i - 1]; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}