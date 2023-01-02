//10-4 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int s_check(char* p, char* q);

int main() {

	int M, K1, K2;
	scanf("%d%d%d", &M, &K1, &K2); // M, K1, K2 입력
	getchar(); // 버퍼에 남은 개행문자 제거


	for (int i = 0; i < M; i++) { // M줄 입력받음
		char str[201] = { '\0' }; // 배열의 원소를 널문자로 모두 초기화
		int cnt = 0; // 소문자 갯수 초기화

		gets(str); // 공백을 포함하여 입력받음

		cnt = s_check(str + K1, str + K2); // K1번째 주소와 K2번째 추소를 인자로 넣어주어 소문자 갯수를 받아옴
		if (cnt == 0) continue; // 소문자가 없으면 출력안함
		printf("%d\n", cnt); // 해당 줄의 소문자 갯수 출력

	}
	return 0;
}

int s_check(char* p, char* q) {

	int cnt_small = 0;
	for (char* i = p; i <= q; i++) { // 포인터 i가 p부터 q까지 가리키며 순환함
		if (*i >= 'a' && *i <= 'z') cnt_small++; // i가 가리키는 문자가 소문자이면 cnt_small 증가
	}
	return cnt_small; // 소문자 갯수 반환
}
