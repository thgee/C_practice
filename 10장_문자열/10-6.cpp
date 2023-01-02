// 10-6

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int getLength(char str[]);

int main() {

	char str1[50], str2[21];
	scanf("%s%s", str1, str2);
	int input;
	scanf("%d", &input);
	int sort;
	scanf("%d", &sort);
	int len1 = getLength(str1);
	int len2 = getLength(str2);

	for (int i = 0; i < len1; i++) {
	
		if (i == input) {
			// input �������� str1�� �ι��ڱ��� len2��ŭ �ڷ� �δ�
			for (int j = len1; j >= i; j--) { 
				str1[j + len2] = str1[j];
			}

			// str2 ����
			if (sort == 0) {
				for (int j = 0; j < len2; j++) {
					str1[i + j] = str2[j];
				}
			}
			else
				for (int j = 0; j < len2; j++) {
					str1[i + len2 - j - 1] = str2[j];
				}
		}
	}

	printf("%s", str1);

	return 0;
}


int getLength(char str[]) {
	int len = 0;
	while (1) {
		if (str[len] == '\0') break;
		len++;
	}
	return len;
}
