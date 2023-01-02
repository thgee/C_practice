// 8-9

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max1;
int max2;

void update_max(int x) {

	if (max1 <= x) { // max1 보다 큰 수
		max2 = max1;
		max1 = x;
	}

	if (max1 > x && max2 < x) { // max1과 max2의 사이
		max2 = x;
	}
}

int main() {

	int N;
	scanf("%d", &N);
	max1 = N;
	scanf("%d", &N);
	max2 = N;
	update_max(N);
	while (1) {
		scanf("%d", &N);
		if (N == 0) break;
		update_max(N);
	}

	printf("%d %d", max1, max2);
	return 0;
}