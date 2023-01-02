// 12-7

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int row, col;
	scanf("%d%d", &row, &col);

	char** p = (char**)malloc(col * sizeof(char*));
	for (int i = 0; i < col; i++)
		p[i] = (char*)malloc(row * sizeof(char));

	int k = 'a';
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {

			p[i][j] = k;
			if (k == 'z') {
				k = 'A'; continue;
			}
			if (k == 'Z') {
				k = 'a'; continue;
			}
			k++;

		}
	}

	for (int i = 0; i < col; i++) {
		printf("\n");
		for (int j = 0; j < row; j++) {
			printf("%c ", p[i][j]);
		}
	}


	for (int i = 0; i < col; i++)
		if (p[i] != NULL)
			free(p[i]);

	if (p != NULL)
		free(p);


	return 0;
}

