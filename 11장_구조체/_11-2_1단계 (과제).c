// 11 - 2 _ 1단계(과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


struct student {
	char name[21];
	int kor, eng, math; // 각 과목의 점수
};

struct average {
	double kor, eng, math; // 각 과목의 평균 점수
};

struct average calculate_avg(struct student* st, int N);


int main() {


	int N; // 학생수 N
	scanf("%d" , &N);

	struct student st[50]; // student 구조체 배열
	struct average avg; // 평균을 저장할 구조체
	int cnt[3] = { 0 }; // 평균 미달을 카운트할 배열


	for (int i = 0; i < N; i++)
		scanf("%s%d%d%d", st[i].name, &(st[i].kor), &(st[i].eng), &(st[i].math)); // student의 정보를 입력받음

	avg = calculate_avg(st, N); // 함수 호출
	
		printf("%.1lf %.1lf %.1lf\n", avg.kor, avg.eng, avg.math); // 각 과목의 평균 출력
	
		for (int i = 0; i < N; i++) {
			if (st[i].kor < avg.kor) cnt[0]++; // 국어 미달학생 수 카운트
			if (st[i].eng < avg.eng) cnt[1]++; // 영어 미달학생 수 카운트
			if (st[i].math < avg.math) cnt[2]++; // 수학 미달학생 수 카운트
		}

		for (int i = 0; i < 3; i++)	
			printf("%d ", cnt[i]); // 미달학생 수 출력

	return 0;
}


struct average calculate_avg(struct student* st, int N) {
	struct average avg; // average 구조체 생성
	int sum_kor = 0, sum_eng = 0, sum_math = 0;
	for (struct student* p = st; p < st + N; p++) {
		 sum_kor += p->kor; // 국어 성적의 합 저장
		 sum_eng += p->eng; // 영어 성적의 합 저장
		 sum_math += p->math; // 수학 성적의 합 저장
	}
	avg.kor = (float)sum_kor / N; // 국어 평균
	avg.eng = (float)sum_eng / N; // 영어 평균
	avg.math = (float)sum_math / N; // 수학평균

	return avg; // 세 과목의 평균이 저장된 avg 반환	
}
