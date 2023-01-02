// 8-13

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count_3(int x);


int main() {

	int N;
	int cnt = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		cnt += count_3(i);
	printf("%d", cnt);

	return 0;
}

int count_3(int x) {
	int cnt = 0;
	while (x) {
		if (x % 10 == 3) cnt++;
		x /= 10;
	}
	return cnt;
}