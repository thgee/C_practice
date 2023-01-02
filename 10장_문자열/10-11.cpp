// 10-11

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int	isIncludeStr(char str1[], char str2[]);

int main() {

	char str1[81];
	char str2[11];

	scanf("%s%s", str1, str2);


	printf("%d %d", strlen(str1), isIncludeStr(str1, str2));

	return 0;
}


int	isIncludeStr(char str1[], char str2[]) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	char* tmp1;
	char* tmp2;
	int cnt = 0;
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			cnt = 0;
			if (str1[i] == str2[j]) {
				tmp1 = &str1[i];
				tmp2 = &str2[j];
				for (int k = 0; k < len2; k++) {
					if (*tmp1 != *tmp2) break;
					tmp1++;
					tmp2++;
					cnt++;
					if (cnt == len2) return 1;
				}
			}
		}
	}
	return 0;
}

