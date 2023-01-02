// 10-6 (Ãß°¡)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int front(char* p, int idx);
int back(char* p, int idx);


int main() {

	char str[101];
	scanf("%s", str);

	for (int i = 0; i < strlen(str); i++) {
	int cnt = 0;
		cnt += front(str, i);
		cnt += back(str, i);
		if (cnt == 2) {
			str[i] -= 'a' - 'A';
		}
	}

	printf("%s", str);

	return 0;
}

int front(char* p, int idx) {
	for (char* i = p; i < p + idx; i++) {
		if (*i == *(p + idx)) return 1;
	}
		return 0;
}
int back(char* p, int idx){
	int len = strlen(p);
	for (char* i = p + len - 1; i > p + idx; i--) {
		if (*i == *(p + idx)) return 1;
	}
		return 0;
}