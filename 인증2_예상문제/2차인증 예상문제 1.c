// 2차인증 예상문제 1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	char buffer[201];
	gets(buffer);
	char str[20][201];
	int num = 0; // 단어갯수



	for (int i = 0, idx = 0, len = 0; i <= strlen(buffer); i++) {
		if (buffer[i] == ' ' || buffer[i] == '\0') {
			strncpy(str[idx], &buffer[i - len], len);
			str[idx][len] = '\0';
				idx++;
				len = 0; // 단어길이
				num++;
		}
		else len++;
	}

	for(int i = 0; i < num; i++)
		printf("%s\n", str[i]);


	for(int i = 0; i < num ; i++)
		for (int j = 0; j < num - i - 1; j++) {
			char tmp[201];
			if (strcmp(str[j], str[j+1]) > 0) {
				strcpy(tmp, str[j]);
				strcpy(str[j], str[j+1]);
				strcpy(str[j+1], tmp);
			}
		}

	for (int i = 0; i < num; i++)
		printf("%s ", str[i]);

	return 0;
}