#define _CRT_SECURE_NO_WARNINGS
#include "my_func.h"

void RegFromFile(TEL** tel_list, int* count, int max_num) {

	FILE* fp = fopen("PHONE_BOOK.txt", "r"); // txt������ �о��
	char buffer[101]; // �ӽ÷� ���ڿ��� ������ ����

	while (1) {

		// ----------- ����ó�� --------------
		if (*count == max_num) { // ����ó ������ max_num ���� �ʰ��ϸ�
			printf("OVERFLOW\n"); // ���޼��� ���
			return; // �޴��� ���ư�
		}


		fgets(buffer, 101, fp); // ������ �� �� �о��
		if (feof(fp)) return; // ������ ���� �����ϸ� �ߴ�

		(*count)++; // ����ó ���� ����



		// tel_list�� ���� �����Ҵ�
		tel_list[*count - 1] = (TEL*)malloc(sizeof(TEL));
		if (tel_list[*count - 1] == NULL) { // �����Ҵ� ���� ���� üũ
			printf("Not enough memory!");
			return -1;
		}

		// --------------- �迭�� ���� ���� ����ó ��� ---------------
		// ----------- ������ �������� �߶� �̸�, ��ȣ, ������� �����Ҵ� �� ���� ------------

		int flag = 1; // �̸�, ��ȣ, ��������� ������ �÷���
		// �̸� : 1	��ȣ : 2	 ������� : 3
		for (int i = 0, start = 0, len = 0; i < strlen(buffer); i++) { // i�� buffer�� ���๮�ڱ��� ��ȯ

			// -------- name �����Ҵ� �� ���� --------- 
			if (buffer[i] == ' ' && flag == 1) { // ù ��° ������ ������
				tel_list[*count - 1]->name = (char*)malloc(sizeof(char) * (len + 1)); // �ܾ��� ���� + 1 ��ŭ �����Ҵ�
				if (tel_list[*count - 1]->name == NULL) { // �����Ҵ� ���� ���� üũ
					printf("Not enough memory!");
					return;
				}
				strncpy(tel_list[*count - 1]->name, &buffer[start], len); // �̸� ����
				tel_list[*count - 1]->name[start + len] = '\0'; // name�� ���� �ι��� ����

				start = i + 1; // start �ε����� ���� �ܾ��� ù��° ���ڿ� ������ ��
				len = 0; // �ܾ��� ���� ����
				flag = 2; // �÷��� ����
			}

			// -------- tel_no �����Ҵ� �� ���� --------- 
			else if (buffer[i] == ' ' && flag == 2) { // �� ��° ������ ������
				tel_list[*count - 1]->tel_no = (char*)malloc(sizeof(char) * (len + 1)); // �ܾ��� ���� + 1 ��ŭ �����Ҵ�
				if (tel_list[*count - 1]->tel_no == NULL) { // �����Ҵ� ���� ���� üũ
					printf("Not enough memory!");
					return;
				}
				strncpy(tel_list[*count - 1]->tel_no, &buffer[start], len); // ��ȭ��ȣ ����
				tel_list[*count - 1]->tel_no[len] = '\0'; // ��ȭ��ȣ�� ���� �ι��� ����

				start = i + 1; // start �ε����� ���� �ܾ��� ù��° ���ڿ� ������ ��
				len = 0; // �ܾ��� ���� ����
				flag = 3; // �÷��� ����
			}


			// -------- birth �����Ҵ� �� ���� --------- 
			else if (buffer[i] == '\n' && flag == 3) { // ���๮�ڸ� ������
				tel_list[*count - 1]->birth = (char*)malloc(sizeof(char) * (len + 1)); // �ܾ��� ���� + 1 ��ŭ �����Ҵ�
				if (tel_list[*count - 1]->birth == NULL) { // �����Ҵ� ���� ���� üũ
					printf("Not enough memory!");
					return;
				}
				strncpy(tel_list[*count - 1]->birth, &buffer[start], len); // ������� ����
				tel_list[*count - 1]->birth[len] = '\0'; // ��������� ���� �ι��� ����

			}

			else len++; // ������ ������ ������ �ܾ��� ���� ī��Ʈ
		}

		sort(tel_list, *count); // ����

	}
	fclose(fp);
}
