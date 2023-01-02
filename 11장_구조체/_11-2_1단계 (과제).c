// 11 - 2 _ 1�ܰ�(����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


struct student {
	char name[21];
	int kor, eng, math; // �� ������ ����
};

struct average {
	double kor, eng, math; // �� ������ ��� ����
};

struct average calculate_avg(struct student* st, int N);


int main() {


	int N; // �л��� N
	scanf("%d" , &N);

	struct student st[50]; // student ����ü �迭
	struct average avg; // ����� ������ ����ü
	int cnt[3] = { 0 }; // ��� �̴��� ī��Ʈ�� �迭


	for (int i = 0; i < N; i++)
		scanf("%s%d%d%d", st[i].name, &(st[i].kor), &(st[i].eng), &(st[i].math)); // student�� ������ �Է¹���

	avg = calculate_avg(st, N); // �Լ� ȣ��
	
		printf("%.1lf %.1lf %.1lf\n", avg.kor, avg.eng, avg.math); // �� ������ ��� ���
	
		for (int i = 0; i < N; i++) {
			if (st[i].kor < avg.kor) cnt[0]++; // ���� �̴��л� �� ī��Ʈ
			if (st[i].eng < avg.eng) cnt[1]++; // ���� �̴��л� �� ī��Ʈ
			if (st[i].math < avg.math) cnt[2]++; // ���� �̴��л� �� ī��Ʈ
		}

		for (int i = 0; i < 3; i++)	
			printf("%d ", cnt[i]); // �̴��л� �� ���

	return 0;
}


struct average calculate_avg(struct student* st, int N) {
	struct average avg; // average ����ü ����
	int sum_kor = 0, sum_eng = 0, sum_math = 0;
	for (struct student* p = st; p < st + N; p++) {
		 sum_kor += p->kor; // ���� ������ �� ����
		 sum_eng += p->eng; // ���� ������ �� ����
		 sum_math += p->math; // ���� ������ �� ����
	}
	avg.kor = (float)sum_kor / N; // ���� ���
	avg.eng = (float)sum_eng / N; // ���� ���
	avg.math = (float)sum_math / N; // �������

	return avg; // �� ������ ����� ����� avg ��ȯ	
}
