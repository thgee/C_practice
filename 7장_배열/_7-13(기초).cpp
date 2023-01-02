// 7-13(±‚√ )

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char str[11];
	scanf("%s", &str);
	

	for(int i = 0; i < 10; i++)
	if ('A' <= str[i] && 'Z' >= str[i]) {
		printf(" %c", str[i]);
	}



	return 0;
}
