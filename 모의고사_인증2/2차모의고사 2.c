#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int N;
	scanf("%d", &N);
	char X[101];
	char buffer[101];
	scanf("%s", X);
	getchar();
	char** Y = (char**)malloc(sizeof(char*) * N);
	if (Y == NULL) {
		printf("not enough memory");
		return -1;
	}

	// �� �� �����Ҵ� �� ����
	for (int i = 0; i < N; i++) {
		gets(buffer);
		Y[i] = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
		if (Y[i] == NULL) {
			printf("not enough memory");
			return -1;
		}
		strcpy(Y[i], buffer);
	}

	int max_idx = 0;
	int max_rep = 0;
	int flag = 0;
	// ----------- �� �ٸ��� �ߺ� �˻� -------
	for (int i = 0; i < N; i++) { // ���� ���

		int rep = 0; // �ݺ�Ƚ��

		for (int j = 0; j < strlen(Y[i]); j++) { // j�� �� ���� �ι��� ������ Ž��
			if (strncmp(&Y[i][j], X, strlen(X)) == 0) { // j���� �����ؼ� Y���� X�� ã����
				rep++;
				j += strlen(X) - 1; // j�� X���̸�ŭ ����
				if (max_rep < rep) {
					max_rep = rep;
					max_idx = i;
				flag = 1;
				}
			}
			
		}
	}

	// -------- ��� ---------
	if (flag == 1)
		printf("%s", Y[max_idx]);
	else
		printf("NONE");

	// ------- ���� ----------
	for (int i = 0; i < N; i++) 
		if (Y[i] != NULL)
			free(Y[i]);
	if (Y != NULL)
		free(Y);


	return 0;
}

/*
3 abc
abcabc abcabc
ABCabc ABCabc
abc abc abc abcd
*/