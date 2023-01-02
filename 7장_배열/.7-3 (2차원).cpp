//7-3 (2Â÷¿ø)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int N;
	char arr[6][6] = { "ZERO-", "ONE--", "TWO--", "THREE", "FOUR-", "FIVE-" };
	

	for (int i = 0; i < 3; i++) {
		scanf("%d", &N);
		printf("%s\n", arr[N]);
	}

	return 0;
}

