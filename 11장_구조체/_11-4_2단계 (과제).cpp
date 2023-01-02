// 11 - 4 _ 2�ܰ� (����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct parking_info {
	int num;					// ���� ��ȣ : ������(4�ڸ�)
	int call;					// �� ��ȭ��ȣ : ������(8�ڸ�)
	char member;			// ��ǰ : ������(S Ȥ�� D)
	char join_member;		// ����� �������� : ������(Y Ȥ�� N) ���ϱ��� �ش���� ����
	int member_type;	// ���� : ������ 7 / 30 / 180 
	int time;					// �����ð�(��) : ������
	double cost;			// ���(��) : �Ǽ���
};

void input(struct parking_info* p, int N);
void compute(struct parking_info* p);
void display(struct parking_info* p, int N);
void parking_info_sort(struct parking_info* p, int N);

int main() {

	int N; // ������ ��
	scanf("%d", &N);
	struct parking_info park[100]; // ������ ����ü �迭
	input(park, N); // ������ ���� �Է�

	for (struct parking_info* i = park; i < park + N; i++)
		compute(i); // ��� ���

	parking_info_sort(park, N); // ����
	display(park, N); // ������ ���� ���

	double cost_D = 0; // D�� ��ü �Ѿ�
		double cost_S = 0; // S�� ��ü �Ѿ�
		double cost_total = 0; // ��ü �Ѿ�

	for (struct parking_info* i = park; i < park + N; i++) {
		if (i->member == 'D') cost_D += i->cost; // D �Ѿ� ����
		if (i->member == 'S') cost_S += i->cost; // S �Ѿ� ����
	}
	cost_total = cost_D + cost_S; // D�Ѿ� + S�Ѿ� == ��ü�Ѿ�


	printf("%.0lf %.0lf %.0lf", cost_D, cost_S, cost_total); // �Ѿ� ���

	return 0;
}


void input(struct parking_info* p, int N) {

	for (struct parking_info* i = p; i < p + N; i++) {
		scanf("%d%d", &i->num, &i->call); // ������ȣ, ��ȭ��ȣ �Է�
		getchar(); // ���� ����
		scanf("%c", &i->member); // ��ǰ �Է�
		getchar(); // ��������
		if (i->member == 'S') // ����� �մ��̶��
			scanf("%c%d", &i->join_member, &i->member_type); // ����� ��������, ���� �Է�
		scanf("%d", &i->time); // �����ð� �Է�
	}
}

void compute(struct parking_info* p) {

	p->cost = 0.0; // �ݾ� �ʱ�ȭ



	// ��ǰ�� ���ϱ��� ��� �⺻��� --------------------------------------------

	if (p->member == 'D')
		p->cost += 5000; // 4�ð� ���ϱ��� �⺻��� 5000��


	// �ʰ���� --------------------------------------------------------------

	if (p->time > 240) {
		p->cost += 200 * ((p->time - 240) / 10); // 4�ð� �ʰ� �� 10�д� 200�� �߰�
	}



	// ��ǰ�� S�̰� ����ǿ� ������ �� �� ��� -----------------------------------

	if (p->member == 'S' && p->join_member == 'N') {
		switch (p->member_type) {
		case 7: // ������ 7��¥�� �� ���
			p->cost += 30000; // 30000�� ������
			break;

		case 30: // ������ 30��¥�� �� ���
			p->cost += 100000; // 100000�� ������
			break;

		case 180: // ������ 180��¥�� �� ���
			p->cost += 500000; // 500000�� ������
		}
	}
}
void display(struct parking_info* p, int N) {
	for (struct parking_info* i = p; i < p + N; i++) {
		printf("%d %d %c %.0lf\n", i->num, i->call, i->member, i->cost); // �������� ���
	}
}

void parking_info_sort(struct parking_info* p, int N) {


	int num_s = 0; // S ��ǰ�� �մ� ��
	int num_d = 0; // D ��ǰ�� �մ� ��

	for (struct parking_info* i = p; i < p + N; i++) {
		if (i->member == 'S') num_s++;  // S��ǰ�� �մԼ� ī��Ʈ
		if (i->member == 'D') num_d++;  // D��ǰ�� �մԼ� ī��Ʈ
	}


	// ��ǰ�� �������� �������� ����

	struct parking_info tmp; // ������ ���� �ӽ� ����ü
	for (struct parking_info* i = p; i < p + N; i++)
		for (struct parking_info* j = i; j < p + N; j++)
			if (i->member > j->member) { // ���� �������� ��ǰ�� Ž������ �������� ��ǰ���� ���ĺ� ������ ū ���̸�
				tmp = *j; // ����
				*j = *i;
				*i = tmp;
			}


	// ���� ��ǰ ������ ���� ��ȣ�� �������� �������� ����


	for (struct parking_info* i = p; i < p + num_d; i++) // D�� ������ŭ Ž��
		for (struct parking_info* j = i; j < p + num_d; j++)
			if (i->num > j->num) { // ���� ��ȣ�� �������� �������� ����
				tmp = *j; // ����
				*j = *i;
				*i = tmp;
			}

	for (struct parking_info* i = p + num_d; i < p + num_d + num_s; i++) // ��ǰ�� D�� �κ��� �ǳʶٰ� Ž��
		for (struct parking_info* j = i; j < p + num_d + num_s; j++)
			if (i->num > j->num) { // ���� ��ȣ�� �������� �������� ����
				tmp = *j; // ����
				*j = *i;
				*i = tmp;
			}

}

