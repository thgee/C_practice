//_12-4_2�ܰ� (����)

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
		if (st[i].name == NULL) { // �����Ҵ� ���� ���� üũ
			printf("Not enough memory!");
			return -1;
		}

		// --------------- �л� �̸� ���� -----------------
		strcpy(st[i].name, buffer);

		// --------------- 1�ܰ� ������ ���� ���� ���� --------------
		scanf("%d%d", &st[i].firstStage, &st[i].interview); // 1�ܰ� ������ ���� ���� �Է¹���

		// -------------- ���� ��� ----------------
		st[i].sum = st[i].firstStage * 7 + st[i].interview * 3; // �л��� ������ ����Ͽ� ������
		st[i].sum /= 10; // �ε��Ҽ��� ������ ���ϱ� ���ؼ� ������ ������ ������ �� ���Ŀ� �ѹ��� 10���� ��������
	}


	// --------------- ���� -----------
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			struct student tmp; // swap�� ���� �ӽ� ����ü
			if (st[j].sum < st[j + 1].sum) { // ���� �������� �������� ����
				tmp = st[j];
				st[j] = st[j + 1];
				st[j + 1] = tmp;
			}
			if (st[j].sum == st[j + 1].sum) { // ������ ���� ���
				if (st[j].firstStage < st[j + 1].firstStage) { // 1�ܰ� ������ �� ���� ����� �������� �������� ����
					tmp = st[j];
					st[j] = st[j + 1];
					st[j + 1] = tmp;
				}
				if (st[j].firstStage == st[j + 1].firstStage) { // 1�ܰ� ������ ������
					if (strcmp(st[j].name, st[j + 1].name) > 0) { // �̸��� ���������� ���� ������� ����
						tmp = st[j];
						st[j] = st[j + 1];
						st[j + 1] = tmp;
					}
				}
			}
		}
	}


		// -------------- ��� -------------------
	
	int num_pass = M; // ���� �հ����� ��
		for (int i = 0; i < M; i++) {
			printf("%s %d %d %.1lf\n", st[i].name, st[i].firstStage, st[i].interview, st[i].sum); // �հ��� ���� ���
		}
			
		for (int i = M - 1; i < N; i++) { // ������ �հ��� ���� �л��� ������ Ž��
			if (st[i].firstStage== st[i + 1].firstStage) { // ������ �հ��ڿ� ����, 1�������� ���� �л��� �հ�
				printf("%s %d %d %.1lf\n", st[i+1].name, st[i + 1].firstStage, st[i + 1].interview, st[i + 1].sum); // �հ��� ���� ���
				num_pass++; // ���� �հ��ڼ� ����
			}
			else break;
		}
		printf("%d", num_pass); // �հ��� �� ���


		// ------------- �޸� ���� -------------

		for (int i = 0; i < N; i++)
			if (st[i].name != NULL)
				free(st[i].name); // �л��� �̸� �޸� ����


		if (st != NULL)
			free(st); // ����ü �迭 st �޸� ����

		return 0;
	}