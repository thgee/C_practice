// 9-5-1 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {

	char str[1000];
	char* p = str; // str 배열을 가리키는 포인터
	int len = 0; // 배열의 길이

	// ------------- input ---------------
	while (true) { // 무한루프
		scanf("%c", p);
		if (*p == '.' || *p == '?' || *p == '!') break; // .?!을 입력받으면 탈출
		p++;
		len++; // 배열길이 증가
	}

	int cnt = 0;
	for (p = str + len - 1; p >= str; p--) { // 배열을 뒤부터 탐색
		if (*p == ' ') { // 공백을 만나면
			for (char* q = p + 1; q <= p + cnt; q++) 
				printf("%c", *q); // 공백 이전에 있던 단어를 출력
			printf(" "); // 띄어쓰기
			cnt = 0;
			continue;
		}

		if (p == str) // p가 str의 시작지점에 도달하면
			for (char* q = str; q <= str + cnt; q++)
				printf("%c", *q); // 맨 처음 단어 출력

		cnt++; // 단어 글자수 카운트
	}

	printf("%c", *(str + len)); // .?! 출력

	return 0;
}

