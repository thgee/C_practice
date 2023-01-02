// 11 - 3 _ 1�ܰ� (����)

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
	struct hotel_info* best_hotel = NULL; // ���������� ������ �����ϴ� ȣ���� ����ų ����ü ������
	while (1) {
		if (G <= p->G && D >= p->D) {// best_hotel �ʱ�ȭ
			best_hotel = p; break;
		}
			p++;
	}
	for (struct hotel_info* i = p; i < p + N; i++) {
		if (G <= i->G && D >= i->D) { // G �̻��� ��ް� D ������ �Ÿ��� ���� ȣ����
			if (best_hotel->score < i->score)
				best_hotel = i; // ���ǵ��� ���� ȣ���� best_hotel�� ����
			else if (best_hotel->score == i->score) // ���ǵ��� ���ٸ�
				if (strcmp(best_hotel->name, i->name) > 0)
					best_hotel = i; // ȣ�� �̸��� �����󿡼� ���� ȣ���� ����
		}
	}
	printf("%s %d %.1lf %.1lf %c", best_hotel->name, best_hotel->G, best_hotel->score, best_hotel->D, best_hotel->bf);
	// best_hotel�� ���� ���
}
