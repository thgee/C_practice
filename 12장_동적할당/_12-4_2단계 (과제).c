//_12-4_2단계 (과제)

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
		if (st[i].name == NULL) { // 동적할당 성공 여부 체크
			printf("Not enough memory!");
			return -1;
		}

		// --------------- 학생 이름 저장 -----------------
		strcpy(st[i].name, buffer);

		// --------------- 1단계 점수와 면접 점수 저장 --------------
		scanf("%d%d", &st[i].firstStage, &st[i].interview); // 1단계 점수와 면접 점수 입력받음

		// -------------- 총점 계산 ----------------
		st[i].sum = st[i].firstStage * 7 + st[i].interview * 3; // 학생의 총점을 계산하여 저장함
		st[i].sum /= 10; // 부동소수점 오차를 피하기 위해서 비율을 정수로 곱해준 후 이후에 한번에 10으로 나누어줌
	}


	// --------------- 정렬 -----------
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			struct student tmp; // swap을 위한 임시 구조체
			if (st[j].sum < st[j + 1].sum) { // 총점 기준으로 내림차순 정렬
				tmp = st[j];
				st[j] = st[j + 1];
				st[j + 1] = tmp;
			}
			if (st[j].sum == st[j + 1].sum) { // 총점이 같을 경우
				if (st[j].firstStage < st[j + 1].firstStage) { // 1단계 점수가 더 높은 사람을 기준으로 내림차순 정렬
					tmp = st[j];
					st[j] = st[j + 1];
					st[j + 1] = tmp;
				}
				if (st[j].firstStage == st[j + 1].firstStage) { // 1단계 점수도 같으면
					if (strcmp(st[j].name, st[j + 1].name) > 0) { // 이름이 사전상으로 빠른 순서대로 정렬
						tmp = st[j];
						st[j] = st[j + 1];
						st[j + 1] = tmp;
					}
				}
			}
		}
	}


		// -------------- 출력 -------------------
	
	int num_pass = M; // 최종 합격자의 수
		for (int i = 0; i < M; i++) {
			printf("%s %d %d %.1lf\n", st[i].name, st[i].firstStage, st[i].interview, st[i].sum); // 합격자 정보 출력
		}
			
		for (int i = M - 1; i < N; i++) { // 마지막 합격자 부터 학생의 끝까지 탐색
			if (st[i].firstStage== st[i + 1].firstStage) { // 마지막 합격자와 평점, 1차성적이 같은 학생도 합격
				printf("%s %d %d %.1lf\n", st[i+1].name, st[i + 1].firstStage, st[i + 1].interview, st[i + 1].sum); // 합격자 정보 출력
				num_pass++; // 최종 합격자수 증가
			}
			else break;
		}
		printf("%d", num_pass); // 합격자 수 출력


		// ------------- 메모리 해제 -------------

		for (int i = 0; i < N; i++)
			if (st[i].name != NULL)
				free(st[i].name); // 학생의 이름 메모리 해제


		if (st != NULL)
			free(st); // 구조체 배열 st 메모리 해제

		return 0;
	}