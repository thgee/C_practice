// 10-3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pushStr(char str[], int len);


int main() {

	char str[1000] = { 0 };
	int i = 0;
	scanf("%s", str);
	while (1) {
		if (str[i] == '\0') break;
		i++;
	}

	str[i] = '\0';

	printf("%s\n", str);
	for (int j = 0; j < i - 1; j++) {

		char tmp = str[0];
		for (int k = 0; k < i - 1; k++) {
			str[k] = str[k + 1];
		}
		str[i - 1] = tmp;
		printf("%s\n", str);
	}

	return 0;
}

void pushStr(char str[], int len) {
	char tmp = str[0];
	for (int i = 0; i < len - 1; i++) {
		str[i] = str[i + 1];
	}
	str[len - 1] = tmp;
}