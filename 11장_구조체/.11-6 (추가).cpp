// .11-6 (추가)cpp

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct student {
	
	int kor, eng, math;
	char name[11];

} student;

typedef struct subject {

	double koravg, engavg, mathavg;
	char top[11]; // 최고점 학생 이름

} subject;


struct subject average(struct student* pst, int N);

int main() {

	int N;
	scanf("%d", & N);
	student st[10];

	for (student* p = st; p < st + N; p++) {
		scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->math);
	}
	
	subject s = average(st, N);

	printf("kor = %.1lf\n", s.koravg);
	printf("eng = %.1lf\n", s.engavg);
	printf("math = %.1lf\n", s.mathavg);
	printf("top = %s",  s.top);

	return 0;
}

struct subject average(struct student* pst, int N) {
	int korSum = 0, engSum = 0, mathSum = 0;
	double avg;
	double max_avg = 0;
	subject s;
	for (student* p = pst; p < pst + N; p++) {
		korSum += p->kor;
		engSum += p->eng;
		mathSum += p->math;
		avg = (p->kor + p->eng + p->math) / 3.0;
		if (max_avg < avg) {
			strcpy(s.top,p->name);
			max_avg = avg;
		}
	}
	s.koravg = (double)korSum / N;
	s.engavg = (double)engSum / N;
	s.mathavg = (double)mathSum / N;
	
	return s;
	
}


