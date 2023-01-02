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

	// 각 줄 동적할당 후 저장
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
	// ----------- 각 줄마다 중복 검사 -------
	for (int i = 0; i < N; i++) { // 한줄 잡고

		int rep = 0; // 반복횟수

		for (int j = 0; j < strlen(Y[i]); j++) { // j가 그 줄의 널문자 전까지 탐색
			if (strncmp(&Y[i][j], X, strlen(X)) == 0) { // j부터 시작해서 Y에서 X를 찾으면
				rep++;
				j += strlen(X) - 1; // j는 X길이만큼 점프
				if (max_rep < rep) {
					max_rep = rep;
					max_idx = i;
				flag = 1;
				}
			}
			
		}
	}

	// -------- 출력 ---------
	if (flag == 1)
		printf("%s", Y[max_idx]);
	else
		printf("NONE");

	// ------- 해제 ----------
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