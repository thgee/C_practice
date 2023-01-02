// 10-1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isSmall(char ch);

int main() {

	char str[21];
	scanf("%s", str);

	int len = 0;
	while (1) {
		if (str[len] == '\0') break;
		len++;
	}

	for (int i = 0; i < len; i++) {
		if(isSmall(str[i])) printf("%c", str[i]);
	}

	return 0;
}

int isSmall(char ch) {
	if (ch >= 'a' && ch <= 'z') return 1;
	return 0;
}
