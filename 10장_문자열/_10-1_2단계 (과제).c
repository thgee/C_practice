//10-1_2단계 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 문자를 적절히 변환하여 res배열에 넣어주는 함수
void changeStr(char str[], char res[], int N);




int main() {

	char str1[22];
	char str2[22];
	gets(str1); // 공백을 포함하여 입력받아야 함
	gets(str2); // 공백을 포함하여 입력받아야 함

	char res1[500]; // str1을 변환시킨 문자열 res1
	char res2[500]; // str2을 변환시킨 문자열 res2

	
	int cnt = 0; // 변경 불가능을 판단하기 위한 변수
	for (int i = 1; i < 27; i++) { // N의 범위는 1~26으로 주어짐 (N이 26까지 순환하면서 함수에 들어가고, 변환이 가능한지 판단)
		changeStr(str1, res1, i); // str1을 변환시켜 res1에 저장 (함수이용)
		changeStr(str2, res2, i); // str2을 변환시켜 res2에 저장
		if (strcmp(res1, str2) == 0) { // str1을 변형한 res1이 str2와 같으면 1을 출력 후 종료 
			printf("%d", 1); break;
		} 

		if (strcmp(res2, str1) == 0) { // str2을 변형한 res2이 str1와 같으면 2를 출력 후 종료 
			printf("%d", 2); break;
		}

		cnt++; // for문을 탈출하지 못했으면 cnt 증가
	}

		if(cnt == 26) printf("%d", 0); // 변경 불가능하면 0을 출력

	return 0;
}


void changeStr(char str[], char res[], int N)
{
	int idx = 0;
	char num[3] = "aa"; // 숫자가 나오면 저장해둘 배열, 문자열 "aa"로 초기화
	for (int i = 0, j = 0; i < strlen(str); i++) { // 문자열의 길이만큼 반복

		if (str[i] >= '0' && str[i] <= '9') { // 숫자일 때
			num[j] = str[i];  // num배열에 현재 숫자 저장
			j++; // 두자리 숫자일 수도 있으므로 다음 자리수를 탐색하기 위해 j를 증가시킴
		}
		else { // 숫자가 아닐 때
			j = 0;
			if (atoi(num) != 0) { // num에 'a' 가 아닌 정수가 들어있으면
				for (int i = 0; i < N; i++) { 
					res[idx] = 'A' + atoi(num) - 1; // num에 들어있는 숫자번째의 대문자를 N번 res에 저장
					idx++; // res 인덱스 증가
				}
			}
			if (str[i] >= 'A' && str[i] <= 'Z') res[idx] = str[i] + N; // 대문자면 아스키 코드 값에서 N을 더한 문자를 저장
			else if (str[i] >= 'a' && str[i] <= 'z') res[idx] = str[i] - N; // 소문자면 아스키 코드 값에서 N을 뺀 문자를 저장
			else res[idx] = ' '; // 그 외 공백 저장
			idx++; // res 인덱스 증가
			num[0] = 'a'; // num 초기화
			num[1] = 'a';
		}

		if (str[i + 1] == '\0' && atoi(num) != 0) // 문자열의 마지막이 숫자로 끝나는 경우
		for (int i = 0; i < N; i++) { // num에 들어있는 숫자 번째의 대문자를 N번 res에 저장
			res[idx] = 'A' + atoi(num) - 1;
			idx++; // res 인덱스 증가
		}
	}
	res[idx] = '\0'; // res의 마지막 인덱스에 널문자 삽입
}

