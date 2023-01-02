// 9-6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char arr[10];

	for (char* p = arr; p < arr + 10; p++)
		scanf("%c", p);

	int cnt = 0, max = 0;
	char ch;

	for (char* p = arr; p < arr + 10; p++) {
		for (char* q = arr; q < arr + 10; q++) {
			if (*p == *q) cnt++;
		}
		if (max < cnt) {
			max = cnt;
			ch = *p;
		}
		cnt = 0;
	}

	printf("%c %d", ch, max);

	return 0;
}