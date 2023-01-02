// 11 - 12

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student {
	char name[20];
	int scr1, scr2, scr3;
	float avg;
};

void read_data(struct student st[]);
void cal_avg(struct student st[]);
void sort(struct student st[]);
void print_score(struct student st[]);

int main() {

	struct student st[10];
	  read_data(st);
		  cal_avg(st);
		  sort(st);
		  print_score(st);

	return 0;
}


void read_data(struct student st[]) {
	for (struct student* p = st; p < st + 10; p++) {
		scanf("%s%d%d%d", &p->name, &p->scr1, &p->scr2, &p->scr3);
	}
}

void cal_avg(struct student st[]) {
	for (struct student* p = st; p < st + 10; p++) {
		p->avg = (p->scr1 + p->scr2 + p->scr3) / 3.0f;
	}
}

void sort(struct student st[]) {
	struct student tmp;
	for (struct student* p = st; p < st + 9; p++) {
		for (struct student* q = p + 1; q < st + 10; q++) {
			if (p->avg < q->avg) {
				tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}
}

void print_score(struct student st[]) {
	printf("%s %.2f\n", st[0].name, st[0].avg);
	printf("%s %.2f\n", st[9].name, st[9].avg);
	printf("%s %.2f\n", st[7].name, st[7].avg);
	printf("%s %.2f\n", st[8].name, st[8].avg);
	printf("%s %.2f\n", st[9].name, st[9].avg);
}
