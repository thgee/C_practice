//_9-5 (추가)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print(char* ch, int N);

int main() {

	char str[100];
	char* p = str;
	int len_str = 0;

	// input 
	while (1) {
		scanf("%c", p);
		len_str++;
		if (*p == '*') break;
		p++;
	}

	int cnt = 0;
	int max = 0; // 가장 긴 단어의 길이
	char* p_max = NULL; // 가장 긴 단어의 시작주소
	for (p = str; p < str + len_str; p++) {
		if (*p == ' ' || *p == '*') {
			printf("%d\n", cnt);
			if (max < cnt) {
				max = cnt;
				p_max = p - cnt;
			}
			cnt = 0;
			continue;
		}
		cnt++;
	}

	print(p_max, max);


	return 0;
}

void print(char* ch, int N) {

	const int DIF = 'a' - 'A';
	// 대문자로 변환
	for (char* p = ch; p < ch + N; p++)
		if (*p >= 'a' && *p <= 'z') (* p) -= DIF;

	// print
	for (char* p = ch; p < ch + N; p++)
		printf("%c", *p);
}
