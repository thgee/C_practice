// 9-3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int N;
	int arr[50];
	int* p;

	scanf("%d", &N);
	for (p = arr; p < arr + N; p++)
		scanf("%d", p);

	int cnt = 0;
	for (p = arr; p < arr + N; p++) {
		if (*p == 0) break;
		cnt++;
	}

	printf("%d", cnt);



	return 0;
}
