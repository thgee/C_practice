//_12-3_2단계 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct subject {
	char* name; // 과목 이름
	double score; // 과목 점수
};

struct student {
	char* name; // 학생 이름
	char id[5]; // 학생 학번
	int numSubject; // 과목 개수
	struct subject* psub; // 과목 구조체 포인터
	double avg; // 모든 과목의 평균 점수
};

double stringToDouble(char str[], int scr_len);

int main() {

	int N;
	scanf("%d", &N); // N명의 학생
	getchar(); // 개행문자 제거
	char buffer[101]; // 학생의 정보를 입력받을 문자열 버퍼

	// --------------- student 구조체 배열 동적할당 ------------------
	struct student* st = (struct student*)malloc(N * sizeof(struct student)); // student 구조체 배열 동적할당
	if (st == NULL) { // 동적할당 성공 여부 체크
		printf("Not enough memory!");
		return -1;
	}

	// ----------------- 문자열을 공백 기준으로 나누어서 구조체에 저장 ------------

	for (int i = 0; i < N; i++) {
		gets(buffer); // 학생의 정보를 하나의 문자열로 입력받음
		

		// ----------- name 저장 ----------------
		int name_len = 0;
		for (int j = 0; j <= strlen(buffer); j++) { // j가 버퍼를 널문자까지 순환함
			if (buffer[j] == ' ') { // 공백을 만나면
				st[i].name = (char*)malloc((name_len + 1) * sizeof(char)); // 학생의 이름을 널문자까지 포함하여 동적할당
				if (st[i].name == NULL) { // 동적할당 성공 여부 체크
					printf("Not enough memory!");
					return -1;
				}
				strncpy(st[i].name, buffer, name_len); // 학생의 이름 저장
				st[i].name[name_len] = '\0'; // 학생의 이름 끝에 널문자를 저장함
				break;
			}
			name_len++; // 이름의 길이 증가
		}

		// -------------- 학번 저장 -----------------
		strncpy(st[i].id, &buffer[name_len + 1], 4); // 학번을 구조체에 저장함
		st[i].id[4] = '\0'; // 학번 끝에 널문자 저장
		
	

		// ------------ 과목 갯수 --------------------
		st[i].numSubject = 0; // 과목 갯수 초기화
		for (int j = name_len + 6; j <= strlen(buffer); j++) { // j가 과목명과 과목점수를 탐색함
			if (buffer[j] == ' ' || buffer[j] == '\0') { // 공백이나 널문자를 만나면
				st[i].numSubject++; // 과목갯수 증가
			}
		}
			st[i].numSubject /= 2; // 실제로 과목 갯수는 카운트 한 것의 절반임

		
		// ---------- 각 student 구조체마다 subject 구조체 배열 동적할당 --------
			st[i].psub = (struct subject*)malloc(sizeof(struct subject) * st[i].numSubject); // 과목갯수만큼의 subject 구조체 배열을 동적할당함
			if (st[i].psub == NULL) { // 동적할당 성공 여부 체크
				printf("Not enough memory!");
				return -1;
			}


			int k = 0; // subject 구조체 배열의 인덱스
			int flag = 0; // flat 0 : 과목명		flag 1 : 과목점수
			int sub_len = 0; // 과목명의 길이
			int scr_len = 0; // 과목점수의 길이
		for (int j = name_len + 6; j <= strlen(buffer); j++) { // j가 과목명과 과목점수를 탐색함

			if (buffer[j] == ' ' && flag == 0) { // 과목명의 끝에 도달하면

			// -------------------- 과목명 동적할당 -----------------------
				st[i].psub[k].name = (char*)malloc(sizeof(char) * (sub_len + 1)); // 과목명의 길이 + 1만큼 subject구조체의 name문자열 동적할당
				if (st[i].psub[k].name == NULL) { // 동적할당 성공 여부 체크
					printf("Not enough memory!");
					return -1;
				}
				
			// -------------------- 과목명 저장 ----------------------------
				strncpy(st[i].psub[k].name, &buffer[j - sub_len], sub_len);  // 과목명을 저장
				st[i].psub[k].name[sub_len] = '\0'; // 과목명 끝에 널문자 저장
				flag = 1; // 다음은 과목점수가 나올 차례임을 알려줌
				scr_len = 0; // 과목점수의 길이 초기화
				continue;
			}

			// -------------------- 과목점수 저장 --------------------------
			if ((buffer[j] == ' ' && flag == 1) || buffer[j] == '\0') { // 과목점수의 끝에 도달하면
				st[i].psub[k].score = stringToDouble(&buffer[j - scr_len], scr_len); // 과목점수 문자열을 double형으로 변환하여 과목점수에 저장
				sub_len = 0; // 과목명 길이 초기화
				k++; // 다음 과목으로 넘어감
				flag = 0; // 다음은 과목명이 나올 차례임을 알려줌
				continue;
			}

			if (flag == 0) sub_len++; // 과목명의 길이 증가
			if (flag == 1) scr_len++; // 과목점수의 길이 증가
		}


		// --------------- 평균 저장 ------------------
			double sum = 0;
		for (int j = 0; j < st[i].numSubject; j++) {
			sum += st[i].psub[j].score; // 학생의 모든 점수를 더함
		}
			st[i].avg = sum / st[i].numSubject; // 평균을 계산해서 avg에 저장

	}
		
	
	// --------------- 평균을 기준으로 내림차순 정렬 -----------------
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			struct student tmp; // swap을 위한 임시 포인터
			if (st[j].avg < st[j + 1].avg) {
				tmp = st[j];
				st[j] = st[j + 1];
				st[j + 1] = tmp;
			}
			if (st[j].avg == st[j + 1].avg) { // 평균점수가 같다면
				if (strcmp(st[j].id, st[j + 1].id) > 0) { // 학번 기준 오름차순 정렬
					tmp = st[j];
					st[j] = st[j + 1];
					st[j + 1] = tmp;
				}
			}
		}
	}
	
	int K;
	scanf("%d", &K); // K번째 학생을 출력할 것임
	K -= 1; // K번째는 배열의 인덱스 상에서 K - 1 번째이다.


// ----------------- K번째 학생의 점수가 가장 높은 과목 저장 ---------------

	double max_scr = st[K].psub[0].score; // 가장 높은 과목의 점수를 저장
	int max_idx = 0; // 가장 높은 점수의 과목 인덱스를 저장
	for (int i = 0; i < st[K].numSubject; i++) {
		if (st[K].psub[i].score > max_scr) { // 현재 과목의 점수가 max_scr보다 크다면
			max_scr = st[K].psub[i].score; // max_scr 갱신
			max_idx = i; // 인덱스 갱신
		}
	}


	// K번째 학생의 정보 출력
	printf("%s %s %.2lf %s %.2lf", st[K].name, st[K].id, st[K].avg, st[K].psub[max_idx].name, max_scr);


	// ------------ 메모리 해제 --------------

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < st[i].numSubject; j++) 
			if(st[i].psub[j].name != NULL)
				free(st[i].psub[j].name); // 학생의 과목명 메모리 해제


	for (int i = 0; i < N; i++) {
		if (st[i].name != NULL)
			free(st[i].name); // 각 학생의 name 메모리 해제
		if (st[i].psub != NULL)
			free(st[i].psub); // 각 학생의 subject 구조체 배열 메모리 해제

	}

	if (st != NULL)
		free(st); // student 구조체배열 메모리 해제


	return 0;
}



double stringToDouble(char str[], int scr_len) { // 문자열을 입력받아서 숫자부분만 잘라낸 후 double형으로 반환하는 함수
	double res = 0;
	for (int i = 0; i < scr_len; i++) {
		res *= 10.0; // 자리수를 증가시킴
		res += ((double)str[i] - '0'); // 일의자리를 double형으로 변환 후 저장
	}
	return res;
}