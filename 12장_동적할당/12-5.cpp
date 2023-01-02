// 12-5

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {

	int N;
	scanf("%d", &N);
	int* p = (int*)calloc(N, sizeof(int));
	if (p == NULL) {
		printf("Not enough Memory");
		return -1;
	}

	for (int i = 0; i < N; i++)
		scanf("%d", &p[i]);

	for (int i = 0; i < N - 1; i++) {
		if (p[i] > p[i + 1]) {
			int tmp;
			tmp = p[i];
			p[i] = p[i + 1];
			p[i + 1] = tmp;
		}
	}

	for (int i = 0; i < N; i++)
		printf("%d\n",p[i]);


	if (p != NULL)
		free(p);

	return 0;
}

