//10-1_1단계 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void changeChar(char ch, int N); // 대문자, 소문자인 경우를 적절히 출력하는 함수
void printRepAlpha(int num, int N); // num번째의 대문자를 N번 출력하는 함수



int main() {

	char str[22];
	int N;
	scanf("%s", str);
	scanf("%d", &N);

	char num[3] = "aa"; // 숫자가 나오면 저장해둘 배열, 문자열 "aa"로 초기화
	for (int i = 0, j = 0; i < strlen(str); i++) { // 문자열의 길이만큼 반복

		if (str[i] >= '0' && str[i] <= '9') { // 숫자일 때
			num[j] = str[i];  // num배열에 현재 숫자 저장
			j++; // 두자리 숫자일 수도 있으므로 다음 자리수를 탐색하기 위해 j를 증가시킴
		}
		else { // 숫자가 아닐 때
			j = 0;
			if (atoi(num) != 0) // num에 'a' 가 아닌 정수가 들어있으면
				printRepAlpha(atoi(num), N); // num에 들어있는 숫자 번째의 대문자를 N번 출력
			changeChar(str[i], N); // 현재 인덱스에 해당하는 문자를 출력함수에 넘겨줌
			num[0] = 'a'; // num 초기화
			num[1] = 'a';
		}

		if(str[i + 1] == '\0' && atoi(num) != 0) // 문자열의 마지막이 숫자로 끝나는 경우
			printRepAlpha(atoi(num), N); // num에 들어있는 숫자 번째의 대문자를 N번 출력

	}

	return 0;
}

void changeChar(char ch, int N) {// 대문자, 소문자인 경우를 적절히 출력하는 함수

	if (ch >= 'A' && ch <= 'Z') printf("%c", ch + N); // 대문자면 아스키 코드 값에서 N을 더한 문자를 출력
	else if (ch >= 'a' && ch <= 'z') printf("%c", ch - N); // 소문자면 아스키 코드 값에서 N을 뺀 문자를 출력
	else printf(" "); // 그 외 공백 출력
}


void printRepAlpha(int num, int N) { // num번째의 대문자를 N번 출력하는 함수
	for (int i = 0; i < N; i++) {
		printf("%c", 'A' + num - 1);
	}
}


