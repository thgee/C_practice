//_9-4 (�߰�)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void repeat(char str[], int N);

int main() {

	char str[100];

	// input
	char* p = str;
	while (1) {
		scanf("%c", p);
		if (*p == '*') break;
		p++;
	}

	int N;
	scanf("%d", &N);

	repeat(str, N);

	// print
	p = str;
	while (1) {
		printf("%c", *p);
		if (*p == '*') break;
		p++;
	}

	return 0;
}

void repeat(char str[], int N) {
	int len = 0;
	char* p = str;

	// str�� ���� len ���ϱ�
	while (1) {
		len++;
		if (*p == '*') break;
		p++;
	}

	char* tmp = str;
	// N�� �ݺ�
	for (int i = 0; i < N; i++) {
		// '*' �������� ��ȯ
		for (p = str; p < str + len - 1; p++) {
			*tmp = *p;
			tmp++;
		}
	}
	*tmp = '*';
}


