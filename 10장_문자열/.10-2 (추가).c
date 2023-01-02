// 10-2 (추가)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main() {

	char str[200];
	gets(str);

	char words[20][200];
	int word_num = 0;
	int word_len = 0;
	int n = strlen(str) + 1;
	for (int i = 0; i < n; i++){
		if (str[i] == '\0' || str[i] == ' ') {
			str[i] = '\0'; // 공백대신 널문자를 넣어줌
			strcpy(words[word_num], &str[i] - word_len);
			word_len = 0;
			word_num++;
			continue;
		}
		
			word_len++;
	}

	for (int i = 0; i < word_num; i++)
		printf("%s\n", words[i]);

	return 0;
}
