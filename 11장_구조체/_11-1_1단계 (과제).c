// _11-1_1�ܰ�(����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

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

	printf(" %s %c", search.id, search.grade); // ���̵�� �̸� ���

	return 0;
}

