//_12-1_1�ܰ� (����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st {
	char* str; // ���ڿ� ����
	int cnt1; // ���� �� ����
	int cnt2; // �� ���� �� ����
};

int main() {


	int N;
	scanf("%d", &N); // N���� ���ڿ�

	char* buffer = (char*)malloc(101 * sizeof(char)); // ���ڿ��� �Է¹��� ���� �����Ҵ�
	if (buffer == NULL) { // �����Ҵ� ���� ���� üũ
		printf("Not enough memory!");
		return -1;
	}


	struct st* p = (struct st*)malloc(N * sizeof(struct st)); // st����ü �迭 �����Ҵ�
	if (p == NULL) { // �����Ҵ� ���� ���� üũ
		printf("Not enough memory!");
		return -1;
	}

	int len = 0;
	for (int i = 0; i < N; i++) {
		scanf("%s", buffer); // buffer�� ���ڿ� �Է�
		len = strlen(buffer); // buffer ���̸� ����
		p[i].str = (char*)malloc((len + 1) * sizeof(char)); // buffer�� ���� + 1��ŭ�� ���ڿ��� �����Ҵ�
		if (p[i].str == NULL) { // �����Ҵ� ���� ���� üũ
			printf("Not enough memory!");
			return -1;
		}
		strcpy(p[i].str, buffer); // ����ü�� str�� buffer�� ����
		p[i].cnt2 = len; // �� ���� �� ����
	}



	// ----------------- ������ �� ���� ----------------------
	for (int i = 0; i < N; i++) {
		p[i].cnt1 = 0; // ������ �� �ʱ�ȭ
		for (int j = 0; j < p[i].cnt2; j++) {
			if (p[i].str[j] == 'a' || p[i].str[j] == 'A' ||
				p[i].str[j] == 'e' || p[i].str[j] == 'E' ||
				p[i].str[j] == 'i' || p[i].str[j] == 'I' ||
				p[i].str[j] == 'o' || p[i].str[j] == 'O' ||
				p[i].str[j] == 'u' || p[i].str[j] == 'U')
				continue; // str�� �� ������ ���鼭 �����̸� continue
			else { // �����̸�
				p[i].cnt1++; // ������ �� ����
			}
		}
	}

	// ------------ ������ �� ���� �������� ���� ----------

	for (int i = 0; i < N; i++) { // ��������
		for (int j = 0; j < N - i - 1; j++) {
			struct st tmp;
			if (p[j].cnt1 < p[j + 1].cnt1) { // �տ� �ִ� ������ ������ ���� �� ũ�ٸ� �ڷ� �б�
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
			if (p[j].cnt1 == p[j + 1].cnt1) { // ������ ������ ���ٸ�
				if (p[j].cnt2 < p[j + 1].cnt2) { // �� ������ ���� ���� �� ���� ����
					tmp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = tmp;
				}
			}
		}
	}

	//  ------------ ��� -------------------

	for (int i = 0; i < N; i++) {
		printf("%s\n", p[i].str);
	}



	// ----------- �޸� ���� -----------------

	if (buffer != NULL)
		free(buffer); // buffer �޸� ����
	for (int i = 0; i < N; i++) {
		if (p[i].str != NULL)
			free(p[i].str); // ������ ���ڿ� �޸� ����
	}
	if (p != NULL)
		free(p); // p �޸� ����

	return 0;
}