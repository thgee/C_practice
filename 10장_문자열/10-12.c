// 10-12

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int	isIncludeStr(char str1[], char str2[]);

int main() {

	char str1[81];
	char str2[11];

	gets(str1);
	scanf("%s", str2);


	printf("%d", isIncludeStr(str1, str2));

	return 0;
}


int	isIncludeStr(char str1[], char str2[]) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	char* tmp1;
	char* tmp2;
	int cnt = 0;
	int res = 0;
	for (int i = 0; i < len1; i++) {
		cnt = 0;
		if (str1[i] == str2[0]) {
			tmp1 = &str1[i];
			tmp2 = str2;
			for (int k = 0; k < len2; k++) {
				if (*tmp1 != *tmp2) break;
				tmp1++;
				tmp2++;
				cnt++;
			}
			if (cnt == len2) {
				res++;
				i += len2 - 1;
			}
		}
	}
	return res;
}

