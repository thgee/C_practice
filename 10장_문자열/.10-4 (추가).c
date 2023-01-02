// 10-4 (�߰�)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void sortDown(char arr[][200], int len);
void dicSort(char arr[][200], int len);

int main() {

	char str[200];
	gets(str);

	char words[20][200];
	int word_num = 0;
	int word_len = 0;
	int n = strlen(str) + 1;
	for (int i = 0; i < n; i++) {
		if (str[i] == '\0' || str[i] == ' ') {
			str[i] = '\0'; // ������ �ι��ڸ� �־���
			strcpy(words[word_num], &str[i] - word_len);
			word_len = 0;
			word_num++;
			continue;
		}

		word_len++; // �迭�� ����
	}

	sortDown(words, word_num);
	dicSort(words, word_num);

	for (int i = 0; i < word_num; i++)	
		printf("%s\n", words[i]);

	return 0;
}

void sortDown(char arr[][200], int len) { // ��������

	char tmp[100] = { '\0' };
	for (int i = 0; i < len - 1; i++) {
		for (int j = i; j < len; j++) {
			if (strlen(arr[i]) < strlen(arr[j])) {
				strcpy(tmp, arr[i]);
				strcpy(arr[i], arr[j]);
				strcpy(arr[j], tmp); // swap
			}
		}
	}
}
void dicSort(char arr[][200], int len) { // ���������� ����
	char tmp[100] = { '\0' };
	for (int i = 0; i < len - 1; i++) {
		for (int j = i; j < len; j++) {
			if (strlen(arr[i]) == strlen(arr[j]) && strcmp(arr[i], arr[j]) > 0) {
				// ���̰� �����鼭 ���������� �����̸�
				strcpy(tmp, arr[i]);
				strcpy(arr[i], arr[j]);
				strcpy(arr[j], tmp); // swap
			}
		}
	}
}


