// 10-3_2단계 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



int main() {

	char str1[200], str2[200];
	gets(str1); // 공백을 포함하여 입력받음
	gets(str2); // 공백을 포함하여 입력받음

	char* p = str1; // 각 단어의 첫 주소를 가리키는 포인터

	int cnt = 0;
	for (int i = 0; i < strlen(str1); i++) { // str1의 길이만큼 반복
		p = &str1[i]; // 그 단어의 첫 번째 주소를 p가 가리킴
		int j = 0; // 다음 단어로 넘어가기 위해 사용할 변수
		while (1) { // 무한루프
			if (p[j] == '.' || p[j] == ' ' || p[j] == '\0') break;
			// .이나 공백이나 널문자를 만나면 탈출
			j++; // 알파벳을 만나면 j 증가
		}
		i += j; // 인덱스를 j만큼(단어의 길이만큼) 증가시켜서 다음 단어를 탐색하게 함


		if (j != 0 && strncmp(p, str2, j) == 0) { // 현재 단어의 길이만큼만 비교해서 str1의 단어와 같다면 cnt 증가
			// 단, .와 공백이 연속으로 나와서 j가 0이 된 상태라면 strncmp 값이 항상 같다고 나오기 때문에 예외처리
			cnt++;
		}
	}
	printf("%d", cnt); // 일치하는 단어 갯수 출력

	return 0;
}

