// 10-5 (�߰�)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int vowel(char ch);

int main() {

	char str1[101], str2[101];
	scanf("%s%s", str1, str2);

	int mode = 1;
	int idx1 = 0, idx2 = 0;
	while (1) {
		if (mode == 1) {
			if (vowel(str1[idx1]) == 0) { // �����̸�
				printf("%c", str1[idx1]); // ���� ���
				idx1++;
			}
			else { // �����̸�
				printf("%c", str1[idx1]); // ���� �ϳ� ���
				idx1++;
				mode = 2;
			}
			if (strlen(str1) == idx1) mode = 2;
			if (idx1 == strlen(str1) && idx2 == strlen(str2)) break;
		}

		if (mode == 2) {
			if (vowel(str2[idx2]) == 0) { // �����̸�
				printf("%c", str2[idx2]); // ���� ���
				idx2++;
			}
			else { // �����̸�
				printf("%c", str2[idx2]); // ���� �ϳ� ���
				idx2++;
				mode = 1;
			}
			if (strlen(str2) == idx2) mode = 1;
			if (idx1 == strlen(str1) && idx2 == strlen(str2)) break;
		}
	}

	return 0;
}

int vowel(char ch) { // ch�� �����̸� 1, �׿� 0 ��ȯ
	// ���� : aioue AIOUE
	if (ch == 'a' ||
		ch == 'i' ||
		ch == 'o' ||
		ch == 'u' ||
		ch == 'e' ||
		ch == 'A' ||
		ch == 'I' ||
		ch == 'O' ||
		ch == 'U' ||
		ch == 'E'
		) {
		return 1;
	}
	else
		return 0;
}
