// 12-3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {

	int N;
	scanf("%d", &N);
	char* p = (char*)malloc(N * sizeof(char));

	scanf("%s", p);
	char a, b;
	getchar();
	scanf("%c %c", &a, &b);

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (p[i] == a) {
			cnt++;
		}
	}
	printf("%d ", cnt);
	cnt = 0;
	for (int i = 0; i < N; i++) {
		if (p[i] == b) {
			cnt++;
		}
	}
	printf("%d ", cnt);

	return 0;
}