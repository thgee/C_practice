// 12-8

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int N;
	scanf("%d", &N);
	char** p = (char**)malloc(N * sizeof(char*));
	if (p == NULL) {
		printf("Not enough momory!");
		return -1;
	}

	for (int i = 0; i < N; i++) {
		char* p[i] = (char*)malloc(N	 * sizeof(char))
		gets(p[i]);
	}


	if(p != NULL)
		free(p);

	return 0;
}

