// 10-8

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	char str1[102], str2[102];
	scanf("%s%s", str1, str2);
	int min_len = strlen(str1) > strlen(str2) ? strlen(str2) : strlen(str1);
	for (int i = 0; i < min_len; i++) {
		if (str1[i] < str2[i]) {
			strcat(str2, str1);
			printf("%s", str2);
			break;
		}
		if (str1[i] > str2[i]) {
			strcat(str1, str2);
			printf("%s", str1);
			break;
		}
	}
	

	return 0;
}

