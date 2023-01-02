//_12-1_1단계 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st {
	char* str; // 문자열 저장
	int cnt1; // 자음 수 저장
	int cnt2; // 총 문자 수 저장
};

int main() {


	int N;
	scanf("%d", &N); // N개의 문자열

	char* buffer = (char*)malloc(101 * sizeof(char)); // 문자열을 입력받을 버퍼 동적할당
	if (buffer == NULL) { // 동적할당 성공 여부 체크
		printf("Not enough memory!");
		return -1;
	}


	struct st* p = (struct st*)malloc(N * sizeof(struct st)); // st구조체 배열 동적할당
	if (p == NULL) { // 동적할당 성공 여부 체크
		printf("Not enough memory!");
		return -1;
	}

	int len = 0;
	for (int i = 0; i < N; i++) {
		scanf("%s", buffer); // buffer에 문자열 입력
		len = strlen(buffer); // buffer 길이를 저장
		p[i].str = (char*)malloc((len + 1) * sizeof(char)); // buffer의 길이 + 1만큼의 문자열을 동적할당
		if (p[i].str == NULL) { // 동적할당 성공 여부 체크
			printf("Not enough memory!");
			return -1;
		}
		strcpy(p[i].str, buffer); // 구조체의 str에 buffer을 저장
		p[i].cnt2 = len; // 총 문자 수 저장
	}



	// ----------------- 자음의 수 저장 ----------------------
	for (int i = 0; i < N; i++) {
		p[i].cnt1 = 0; // 자음의 수 초기화
		for (int j = 0; j < p[i].cnt2; j++) {
			if (p[i].str[j] == 'a' || p[i].str[j] == 'A' ||
				p[i].str[j] == 'e' || p[i].str[j] == 'E' ||
				p[i].str[j] == 'i' || p[i].str[j] == 'I' ||
				p[i].str[j] == 'o' || p[i].str[j] == 'O' ||
				p[i].str[j] == 'u' || p[i].str[j] == 'U')
				continue; // str을 한 음절씩 돌면서 모음이면 continue
			else { // 자음이면
				p[i].cnt1++; // 자음의 수 증가
			}
		}
	}

	// ------------ 자음의 수 기준 내림차순 정렬 ----------

	for (int i = 0; i < N; i++) { // 버블정렬
		for (int j = 0; j < N - i - 1; j++) {
			struct st tmp;
			if (p[j].cnt1 < p[j + 1].cnt1) { // 앞에 있는 원소의 자음의 수가 더 크다면 뒤로 밀기
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
			if (p[j].cnt1 == p[j + 1].cnt1) { // 자음의 갯수가 같다면
				if (p[j].cnt2 < p[j + 1].cnt2) { // 총 문자의 수가 많은 것 부터 정렬
					tmp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = tmp;
				}
			}
		}
	}

	//  ------------ 출력 -------------------

	for (int i = 0; i < N; i++) {
		printf("%s\n", p[i].str);
	}



	// ----------- 메모리 해제 -----------------

	if (buffer != NULL)
		free(buffer); // buffer 메모리 해제
	for (int i = 0; i < N; i++) {
		if (p[i].str != NULL)
			free(p[i].str); // 각각의 문자열 메모리 해제
	}
	if (p != NULL)
		free(p); // p 메모리 해제

	return 0;
}