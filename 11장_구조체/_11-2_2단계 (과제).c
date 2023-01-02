// 11 - 2 _ 2단계(과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


struct student {
	char name[21];
	int kor, eng, math; // 각 과목의 점수
	double avg; // 세 과목의 평균점수
};

void read_data(struct student* pst, int N);
void sort_score(struct student* pst, int N);
struct student* select_out(struct student* pst1, struct student* pst2, int N);


int main() {

	int N; // 학생 수
	scanf("%d", &N);
	struct student st1[49], st2[49]; // 학생 구조체 배열

	read_data(st1, N); // 학생들의 데이터 입력받음
	read_data(st2, N);
	sort_score(st1, N); // 학생들을 점수순으로 정렬
	sort_score(st2, N);
	struct student *st = select_out(st1, st2, N); // 중간등수의 점수가 더 큰 배열 저장

	for (struct student *p = st; p < st + N; p++)
		printf("%s %d %d %d %.1lf\n", p->name, p->kor, p->eng, p->math, p->avg); // 출력

	return 0;
}


void read_data(struct student* pst, int N) {
	for (struct student* p = pst; p < pst + N; p++) {
		scanf("%s%d%d%d", p->name, &p->kor, &p->eng, &p->math); // 이름, 과목3개 점수 입력받음
		p->avg = (p->kor + p->eng + p->math) / 3.0; // 점수의 평균을 계산해서 avg멤버변수에 넣어줌
	}
}

void sort_score(struct student* pst, int N) {
	struct student tmp; // swap을 위해 임시로 저장할 구조체
	for (struct student* p = pst; p < pst + N - 1; p++)
		for (struct student* q = p; q < pst + N; q++) {
			if (p->avg < q->avg) { // 탐색중인 학생이 현재 학생보다 avg가 크다면
				tmp = *p; // swap
				*p = *q;
				*q = tmp;
			}
			else if (p->avg == q->avg) { // 만약 평균이 같다면
				if (p->kor < q->kor) { // 국어점수로 비교
					tmp = *p; // swap
					*p = *q;
					*q = tmp;
				}
				else if (p->kor == q->kor) { // 국어점수도 같다면
					if (p->eng < q->eng) { // 영어점수로 비교
						tmp = *p; // swap
						*p = *q;
						*q = tmp;
					}
					else if (p->eng == q->eng) {// 영어점수도 같다면
						if (p->math < q->math) { // 수학점수로 비교
							tmp = *p; // swap
							*p = *q;
							*q = tmp;
						}
					}
				}
			}
		}
}

struct student* select_out(struct student* pst1, struct student* pst2, int N) {
	if ((pst1 + (N / 2))->avg < (pst2 + (N / 2))->avg) // st2 배열의 중간등수의 평균이 더 크다면
		return pst2; // st2의 주솟값 반환
	else // st1이 더 크다면
		return pst1; // st1의 주솟값 반환
}
