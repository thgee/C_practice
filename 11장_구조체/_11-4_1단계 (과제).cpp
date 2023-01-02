// 11 - 4 _ 1�ܰ� (����)

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

int main() {

	int N; // ������ ��
	scanf("%d", &N);
	struct parking_info park[100]; // ������ ����ü �迭
	input(park, N); // ������ ���� �Է�

	for (struct parking_info* i = park; i < park + N; i++)
		compute(i); // ��� ���

	display(park, N); // ������ ���� ���

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