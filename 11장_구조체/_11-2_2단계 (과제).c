// 11 - 2 _ 2�ܰ�(����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


struct student {
	char name[21];
	int kor, eng, math; // �� ������ ����
	double avg; // �� ������ �������
};

void read_data(struct student* pst, int N);
void sort_score(struct student* pst, int N);
struct student* select_out(struct student* pst1, struct student* pst2, int N);


int main() {

	int N; // �л� ��
	scanf("%d", &N);
	struct student st1[49], st2[49]; // �л� ����ü �迭

	read_data(st1, N); // �л����� ������ �Է¹���
	read_data(st2, N);
	sort_score(st1, N); // �л����� ���������� ����
	sort_score(st2, N);
	struct student *st = select_out(st1, st2, N); // �߰������ ������ �� ū �迭 ����

	for (struct student *p = st; p < st + N; p++)
		printf("%s %d %d %d %.1lf\n", p->name, p->kor, p->eng, p->math, p->avg); // ���

	return 0;
}


void read_data(struct student* pst, int N) {
	for (struct student* p = pst; p < pst + N; p++) {
		scanf("%s%d%d%d", p->name, &p->kor, &p->eng, &p->math); // �̸�, ����3�� ���� �Է¹���
		p->avg = (p->kor + p->eng + p->math) / 3.0; // ������ ����� ����ؼ� avg��������� �־���
	}
}

void sort_score(struct student* pst, int N) {
	struct student tmp; // swap�� ���� �ӽ÷� ������ ����ü
	for (struct student* p = pst; p < pst + N - 1; p++)
		for (struct student* q = p; q < pst + N; q++) {
			if (p->avg < q->avg) { // Ž������ �л��� ���� �л����� avg�� ũ�ٸ�
				tmp = *p; // swap
				*p = *q;
				*q = tmp;
			}
			else if (p->avg == q->avg) { // ���� ����� ���ٸ�
				if (p->kor < q->kor) { // ���������� ��
					tmp = *p; // swap
					*p = *q;
					*q = tmp;
				}
				else if (p->kor == q->kor) { // ���������� ���ٸ�
					if (p->eng < q->eng) { // ���������� ��
						tmp = *p; // swap
						*p = *q;
						*q = tmp;
					}
					else if (p->eng == q->eng) {// ���������� ���ٸ�
						if (p->math < q->math) { // ���������� ��
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
	if ((pst1 + (N / 2))->avg < (pst2 + (N / 2))->avg) // st2 �迭�� �߰������ ����� �� ũ�ٸ�
		return pst2; // st2�� �ּڰ� ��ȯ
	else // st1�� �� ũ�ٸ�
		return pst1; // st1�� �ּڰ� ��ȯ
}
