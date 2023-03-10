// .9-3-1 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isSmall(char ch); // 문자가 소문자인지 판단하는 함수

int main() {

	char str[100];
	int len = 0; // 배열의 길이를 나타내는 변수

	// input
	char* p_str = str; // str을 가리키는 포인터 p_str 선언
	while (1) { // 무한루프
		scanf("%c", p_str);
		if (*p_str == '#') break; // # 문자를 입력받으면 무한루프 종료
		p_str++;
		len++; // 배열길이 + 1
	}

	int max = 0, cnt = 0; // max : 가장 긴 단어의 길이 cnt : 현재 단어의 길이
	for (p_str = str; p_str <= str + len; p_str++) {
		if (isSmall(*p_str)) { // 현재 가리키는 문자가 소문자이면
			printf("%c", *p_str); // 그 문자를 출력
			cnt++; // 단어 길이 + 1
		}
		else {
			if (isSmall(*(p_str + 1))) printf("\n"); // 새로운 단어 시작시 개행
			if (max < cnt) {  // 현재 단어의 길이가 가장 긴 단어의 길이보다 길면
				max = cnt; // 가장 긴 길이를 갱신
			}
			cnt = 0; // 단어길이 초기화
		}
	}

	printf("\n%d", max); // 가장 긴 단어의 길이 출력

	return 0;
}


int isSmall(char ch) {
	if('a' <= ch && 'z' >= ch) return 1; // 소문자이면 true 반환
	return 0;
}
