// 12-6

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int N;
	scanf("%d", &N);
	char* p = (char*)malloc((N + 1) * sizeof(char));
	if (p == NULL) {
		printf("Not enough memory!");
		return -1;
	}
	
	int cnt = 0;
	scanf("%s", p);
	for (int i = 0; i < N; i++) {
		if (strncmp(&p[i], "cat", 3) == 0) {
			cnt++;
			i += 2;
		}
	}

	printf("%d", cnt);

	if (p != NULL)
		free(p);

	return 0;
}

