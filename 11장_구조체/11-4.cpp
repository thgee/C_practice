// 11 - 4

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student {
	char name[20];
	int scr1, scr2, scr3;
	float avg;
	char grade;
};


int main() {

	int N;
	scanf("%d", &N);
	struct student std[20];

	for (int i = 0; i < N; i++) {
		scanf("%s%d%d%d", &std[i].name, &std[i].scr1, &std[i].scr2, &std[i].scr3);
		std[i].avg = (std[i].scr1 + std[i].scr2 + std[i].scr3) / 3.0f;
	}

	for (int i = 0; i < N; i++) {
		if (std[i].avg >= 90) std[i].grade = 'A';
		else if (std[i].avg >= 80) std[i].grade = 'B';
		else if (std[i].avg >= 70) std[i].grade = 'C';
		else std[i].grade = 'F';
	}

	for (int i = 0; i < N; i++) {
		printf("%s %.1f %c\n", std[i].name, std[i].avg, std[i].grade);
	}

	return 0;
}