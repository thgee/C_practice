// 9-2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char ch[20];
	scanf("%s", ch);
	
	char* pch;
	for (pch = ch;; pch++) {
		if (*pch == '#') break;
	}
	for (pch-= 1; pch >= ch; pch--) {
		printf("%c ", *pch);
	}

	return 0;
}
