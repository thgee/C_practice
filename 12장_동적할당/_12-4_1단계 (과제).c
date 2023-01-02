//_12-4_1단계 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
	char* name; // 이름 저장
	int firstStage; // 1단계 점수 저장
	int interview; // 면접 점수 저장
	double sum; // 총점 저장
};


int main() {

	int N, M; // 1단계 합격자 N명, 2단계 합격자 M명
	scanf("%d%d", &N, &M);
	
	
	// ------------- student 구조체 배열 동적할당 ---------

	struct student* st = (struct student*)malloc(sizeof(struct student) * N);
	if (st == NULL) { // 동적할당 성공 여부 체크
		printf("Not enough memory!");
		return -1;
	}


	char buffer[11]; // 이름을 입력받을 임시버퍼
	for (int i = 0; i < N; i++) {

		scanf("%s", buffer); // 학생의 이름을 버퍼에 입력받음

		// ------------- 학생의 이름 동적할당 --------------
		st[i].name = (char*)malloc(sizeof(char) * (strlen(buffer) + 1)); // 학생 이름의 길이 + 1만큼 동적할당
		if(st[i].name == NULL){ // 동적할당 성공 여부 체크
			printf("Not enough memory!");
			return -1;
		}

		// --------------- 학생 이름 저장 -----------------
		strcpy(st[i].name, buffer);

		// --------------- 1단계 점수와 면접 점수 저장 --------------
		scanf("%d%d", &st[i].firstStage, &st[i].interview); // 1단계 점수와 면접 점수 입력받음

		// -------------- 총점 계산 ----------------
		st[i].sum = st[i].firstStage * 0.7 + st[i].interview * 0.3; // 학생의 총점을 계산하여 저장함
	}


	// --------------- 총점이 높은 순부터 내림차순 정렬 -----------
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			struct student tmp; // swap을 위한 임시 구조체
			if (st[j].sum < st[j + 1].sum) { // 버블정렬 수행
				tmp = st[j];
				st[j] = st[j + 1];
				st[j + 1] = tmp;
			}
		}
	}

	// -------------- 출력 -------------------
	for (int i = 0; i < M; i++) {
		printf("%s %.1lf\n", st[i].name, st[i].sum);
	}


	// ------------- 메모리 해제 -------------
	
	for (int i = 0; i < N; i++)
		if (st[i].name != NULL)
			free(st[i].name); // 학생의 이름 메모리 해제
	

	if (st != NULL)
		free(st); // 구조체 배열 st 메모리 해제

	return 0;
}