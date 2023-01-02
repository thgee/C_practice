// ���ǰ�� 5-3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct person {
	char name[11];
	int scr1, scr2; // �ʱ�, ���� ����
	double tot; // �ʱ� 80%, ���� 20%
	int year, mon, day;
} person;

	void swap(struct person* p, struct person* q);


int main() {

	int N, M; // �����ڼ�, �հ��ڼ�
	scanf("%d%d", &N, &M);
	person p[100];

	// ���� �Է�
	for (int i = 0; i < N; i++) {
		scanf("%s", p[i].name);
		scanf("%d-%d-%d", &p[i].year, &p[i].mon, &p[i].day);
		scanf("%d%d", &p[i].scr1, &p[i].scr2);
	}

	// tot���� ����
	for (int i = 0; i < N; i++) {
		p[i].tot = p[i].scr1 * 0.8 + p[i].scr2 * 0.2;
	}

	// �������� ����
	for (int i = 0; i < N - 1; i++) {
		for (int j = i; j < N; j++) {
			if (p[i].tot < p[j].tot) {
				swap(&p[i], &p[j]);
			}
			else if (p[i].tot == p[j].tot) {
				if (p[i].scr1 < p[j].scr1) swap(&p[i], &p[j]);
				else if (p[i].scr1 == p[j].scr1) {
					if(p[i].year < p[j].year) swap(&p[i], &p[j]);
					else if (p[i].year == p[j].year) {
						if (p[i].mon < p[j].mon) swap(&p[i], &p[j]);
						else if (p[i].mon == p[j].mon) {
							if (p[i].day < p[j].day)swap(&p[i], &p[j]);
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < M; i++) {
		printf("%s %.1lf\n", p[i].name, p[i].tot);
	}


	return 0;
}

void swap(struct person* p, struct person* q) {
	person tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}
