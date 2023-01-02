// 11 - 3 _ 2�ܰ� (����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct hotel_info {
	char name[31];
	int G; // ��� 1~5
	double score; // ���ǵ� 1~5
	double D; // �Ÿ�
	char bf; // �������Կ��� Y or N
};

int in_hotel_info(struct hotel_info* p);
void out_hotel_info(struct hotel_info* p, int N, int G, double D);



int main() {


	struct hotel_info hotels[100]; // ȣ�� ����ü �迭
	int N = in_hotel_info(hotels); // ȣ�������� �Է¹ް� ȣ���� ���� ������

	int G; // ȣ���� ���
	double D; // �Ÿ����� �Է�
	scanf("%d%lf", &G, &D);

	
	out_hotel_info(hotels, N, G, D); // ���ǿ� �´� ȣ�� ���
	
	return 0;
}


int in_hotel_info(struct hotel_info* p) {
	int N = 0; // �Է¹��� ȣ���� ��
	for (struct hotel_info* i = p;; i++) {
		scanf("%s", i->name); // ȣ���� �̸� �Է¹���
		if (*(i->name) == '0') break; // ȣ���� �̸����� 0�� �Է¹����� ����
		scanf("%d%lf%lf", &i->G, &i->score, &i->D); // ȣ���� ������ �Է¹���
		getchar(); // ���� ����
		scanf("%c", &i->bf); // ȣ���� ������������ �Է�
		N++; // �Է¹��� ȣ�� �� ����
	}
	return N; // ������ �Էµ� ȣ���� �� ��ȯ
}


void out_hotel_info(struct hotel_info* p, int N, int G, double D) {

	struct hotel_info tmp = *p; // swap�� ���� �ӽ� ����ü

	// --------------- ���ǵ��� �������� �������� ���� -------------------------
	for (struct hotel_info* i = p; i < p + N; i++) {
		for (struct hotel_info* j = i; j < p + N; j++) {
				if (i->score < j->score) { // ���� ȣ���� ���ǵ����� Ž������ ȣ���� ���ǵ��� �� ũ��
					tmp = *i; // swap
					*i = *j;
					*j = tmp;
				}
				else if (i->score == j->score) // ���ǵ��� ���ٸ�
					if (strcmp(i->name, j->name) > 0) {
						tmp = *i; // ȣ�� �̸��� �����󿡼� ���� ȣ���� ã���� ����
						*i = *j;
						*j = tmp;
					}
		}
	}
	

	for (struct hotel_info* i = p; i < p + N; i++) // ���ĵ� ����ü �迭�� Ž��
		if (G <= i->G && D >= i->D) // ������ �����ϸ�
			printf("%s %d %.1lf %.1lf %c\n", i->name, i->G, i->score, i->D, i->bf); // ȣ������ ���
}
