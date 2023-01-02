// 10-10

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	int N;
	char str[100][101];
	scanf("%d", &N);

	getchar();
	gets(str[0]);

	char* p = str[0];
	int min = strlen(str[0]);
	for (int i = 1; i < N; i++) {
		gets(str[i]);
		if (min > strlen(str[i])) {
			p = str[i];
			min = strlen(str[i]);
		}
	}
	printf("%s", p);


	return 0;
}
