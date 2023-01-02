//_12-4_1�ܰ� (����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
	char* name; // �̸� ����
	int firstStage; // 1�ܰ� ���� ����
	int interview; // ���� ���� ����
	double sum; // ���� ����
};


int main() {

	int N, M; // 1�ܰ� �հ��� N��, 2�ܰ� �հ��� M��
	scanf("%d%d", &N, &M);
	
	
	// ------------- student ����ü �迭 �����Ҵ� ---------

	struct student* st = (struct student*)malloc(sizeof(struct student) * N);
	if (st == NULL) { // �����Ҵ� ���� ���� üũ
		printf("Not enough memory!");
		return -1;
	}


	char buffer[11]; // �̸��� �Է¹��� �ӽù���
	for (int i = 0; i < N; i++) {

		scanf("%s", buffer); // �л��� �̸��� ���ۿ� �Է¹���

		// ------------- �л��� �̸� �����Ҵ� --------------
		st[i].name = (char*)malloc(sizeof(char) * (strlen(buffer) + 1)); // �л� �̸��� ���� + 1��ŭ �����Ҵ�
		if(st[i].name == NULL){ // �����Ҵ� ���� ���� üũ
			printf("Not enough memory!");
			return -1;
		}

		// --------------- �л� �̸� ���� -----------------
		strcpy(st[i].name, buffer);

		// --------------- 1�ܰ� ������ ���� ���� ���� --------------
		scanf("%d%d", &st[i].firstStage, &st[i].interview); // 1�ܰ� ������ ���� ���� �Է¹���

		// -------------- ���� ��� ----------------
		st[i].sum = st[i].firstStage * 0.7 + st[i].interview * 0.3; // �л��� ������ ����Ͽ� ������
	}


	// --------------- ������ ���� ������ �������� ���� -----------
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			struct student tmp; // swap�� ���� �ӽ� ����ü
			if (st[j].sum < st[j + 1].sum) { // �������� ����
				tmp = st[j];
				st[j] = st[j + 1];
				st[j + 1] = tmp;
			}
		}
	}

	// -------------- ��� -------------------
	for (int i = 0; i < M; i++) {
		printf("%s %.1lf\n", st[i].name, st[i].sum);
	}


	// ------------- �޸� ���� -------------
	
	for (int i = 0; i < N; i++)
		if (st[i].name != NULL)
			free(st[i].name); // �л��� �̸� �޸� ����
	

	if (st != NULL)
		free(st); // ����ü �迭 st �޸� ����

	return 0;
}