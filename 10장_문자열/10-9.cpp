// 10-9

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int check(char *p);

int main() {

	char str[31];
	scanf("%s", str);
	printf("%d %d", strlen(str), check(str));

	return 0;
}

int check(char* p) {
	int len = strlen(p);
	for (int i = 0; i < len - i; i++) {
		if (p[i] == p[len - 1 - i]) continue;
		return 0;
	}
	return 1;

}
