// _11-1_2�ܰ�(����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
	char name[10]; // �̸�
	char id[11]; // �й�
	char grade; // ����

};

int main() {

	struct student st[5];
	struct student search;

	for (int i = 0; i < 5; i++) {
		scanf("%s%s", &st[i].name, &st[i].id); // �л����� �̸�, �й� �Է�
		getchar(); // ���๮�ڸ� ������
		scanf("%c", &st[i].grade); // ���� �Է�
	}

	scanf("%s", &search.name); // search ����ü�� name �Է�


	for (int i = 0; i < 5; i++) {
		if (strcmp(search.name, st[i].name) == 0) { // �̸��� �������� �л��� ã��
			search = st[i]; // ã�� �л��� search ����ü�� ����
		}
	}

	int cnt = 0; // ���ǿ� �´� �л��� �ϳ��� ���� ��츦 ó���� ����
	for (int i = 0; i < 5; i++) {
		if (search.grade == st[i].grade && strncmp(st[i].id, search.id, 4) == 0) { // ������ �����鼭 ���г⵵�� ������
			if (strcmp(search.name, st[i].name) == 0) continue; // �ڱ� �ڽ��� ������� ����
			printf("%s ", st[i].name); // �̸��� ���
		}
		else cnt++; // ���ǿ� �´� �л��� �ƴ� �� cnt ����
	}
	
	if (cnt == 4) printf("%d", 0); // ���ǿ� �´� �л��� �ϳ��� ������ 0 ���

	printf("\n"); // ����

	char str_year[5]; // ���г⵵
	int year;
	strncpy(str_year, search.id, 4); // �й����� �� 4�ڸ��� ������ year�� ������
	year = atoi(str_year); // ���г⵵�� ���������� ��ȯ��
	printf("%d %d", year, year % 131); // ���г⵵�� 131�� ���� �������� ���
	

	return 0;
}

