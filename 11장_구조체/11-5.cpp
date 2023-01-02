// 11 - 5




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>




int main() {

	struct student {
		char name[20];
		int kor, eng, math;
		float avg;
		char grade;
	};

	int N;
	scanf("%d", &N);
	struct student std[50];
	struct student* p;

	for (p = std; p < std + N; p++) {
		scanf("%s%d%d%d", &(p->name), &(p->kor), &(p->eng), &(p->math));
		p->avg = (p->kor + ( * p).eng + p->math) / 3.0f;
	}

	for (p = std; p < std + N; p++) {
		if (p->avg >= 90) p ->grade = 'A';
		else if (p->avg >= 80) p->grade = 'B';
		else if (p->avg >= 70) p->grade = 'C';
		else p->grade = 'D';
	}

	for (p = std; p < std + N; p++) {
		printf("%s %.1f %c\n", p->name, p->avg, p->grade);
	}

	return 0;
}