#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct string {
	char* str; // ���ڿ��� ����Ű�� ������, ���� �迭 (char str[])�� ������ ��� 50% ����
	int words; // str�� ����Ű�� ���ڿ��� ���Ե� �ܾ� ��
};



int main() {

	int N;
	scanf("%d", &N);
	char buffer[101];

	struct string* arr = (struct string*)malloc(sizeof(struct string) * N);
	if (arr == NULL) {
		printf("not enough memory");
		return -1;
	}
	getchar();
	for (int i = 0; i < N; i++) {
		gets(buffer);
		arr[i].str = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
		if (arr[i].str == NULL) {
			printf("not enough memory");
			return -1;
		}
		strcpy(arr[i].str, buffer);
		arr[i].words = 0;
	}

	// -------- �ܾ�� ����--------
	for (int i = 0; i < N; i++) { // ���� ���
		for (int j = 0; j <= strlen(arr[i].str); j++) { // j�� �� ���� �ι��ڱ��� Ž��
			
			if (arr[i].str[j] == ' ' || arr[i].str[j] == '\0') // ���� or �ι��ڸ�
				arr[i].words++; 
	}
}

	// ---------- sort ----------
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N - i - 1; j++) {
			struct string tmp;
			if (arr[j].words < arr[j + 1].words) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}

	// ------- ��� ---------
	for (int i = 0; i < N; i++)
		printf("%s %d\n", arr[i].str, arr[i].words);

	// -------- ���� ---------
	for (int i = 0; i < N; i++) 
		if (arr[i].str != NULL) 
			free(arr[i].str);

	if (arr != NULL)
		free(arr);

	return 0;
}

	/*
	
5
why so serious
icecream makes everything better
you make me smile
c language midterm and final
see you
	*/