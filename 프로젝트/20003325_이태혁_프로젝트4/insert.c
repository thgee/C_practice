#define _CRT_SECURE_NO_WARNINGS
#include "my_func.h"

void insert(TEL** tel_list, int* count, int max_num) {

	// ----------- ����ó�� --------------
	if (*count == max_num) { // ����ó ������ max_num ���� �ʰ��ϸ�
		printf("OVERFLOW\n"); // ���޼��� ���
		return; // �޴��� ���ư�
	}

	(*count)++; // ����ó ���� ����

	// --------------- �迭�� ���� ���� ����ó ��� ---------------

	// ----------- tel_list �ȿ� ����ó �����Ҵ� ------------

	tel_list[*count - 1] = (TEL*)malloc(sizeof(TEL));
	if (tel_list[*count - 1] == NULL) { // �����Ҵ� ���� ���� üũ
		printf("Not enough memory!");
		return;
	}



	char buffer[101]; // ���ڿ��� �ӽ÷� �Է¹��� ����, ũ��� �ι��ڸ� ���� 100����Ʈ

	// -------- name �����Ҵ� �� ���� --------- 
	printf("Name:"); // �̸� �Է�
	scanf("%s", buffer);
	tel_list[*count - 1]->name = (char*)malloc(sizeof(char) * (strlen(buffer) + 1)); // buffer�� �Էµ� ���ڿ��� ���� + 1 ��ŭ �����Ҵ�
	if (tel_list[*count - 1]->name == NULL) { // �����Ҵ� ���� ���� üũ
		printf("Not enough memory!");
		return;
	}
	strcpy(tel_list[*count - 1]->name, buffer); // �̸� ����

	// -------------- tel_no �����Ҵ� �� ���� ------------

	printf("Phone_number:");
	scanf("%s", buffer); // ��ȣ�� ���ۿ� �Է¹���
	tel_list[*count - 1]->tel_no = (char*)malloc(sizeof(char) * (strlen(buffer) + 1)); // buffer�� �Էµ� ���ڿ��� ���� + 1 ��ŭ �����Ҵ�
	if (tel_list[*count - 1]->tel_no == NULL) { // �����Ҵ� ���� ���� üũ
		printf("Not enough memory!");
		return;
	}
	strcpy(tel_list[*count - 1]->tel_no, buffer); // ��ȣ ����


	// -------------- birth �����Ҵ� �� ���� ------------

	printf("Birth:");
	scanf("%s", buffer); // ��������� ���ۿ� �Է¹���
	tel_list[*count - 1]->birth = (char*)malloc(sizeof(char) * (strlen(buffer) + 1)); // buffer�� �Էµ� ���ڿ��� ���� + 1 ��ŭ �����Ҵ�
	if (tel_list[*count - 1]->birth == NULL) { // �����Ҵ� ���� ���� üũ
		printf("Not enough memory!");
		return;
	}
	strcpy(tel_list[*count - 1]->birth, buffer); // ������� ����

	sort(tel_list, *count); // ����

	printf("<<%d>> \n", *count); // ����ó ���� ���
	return;
}
