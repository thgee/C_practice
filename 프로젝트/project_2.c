// ����ó ���� ���α׷�

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tel {
	char* name; // �̸�
	char* tel_no; // ��ȭ��ȣ
	char* birth; // �������
};
typedef struct tel TEL;

void insert(TEL** tel_list, int* count, int max_num);
void print_all(TEL** tel_list, int count);
void delete_tel(TEL** tel_list, int* count);
void find_by_birth(TEL** tel_list, int count);

int main() {

	int max_num; // �ִ� ����ó ����, ����ڷκ��� �Է¹���
	printf("Max_num:");
	scanf("%d", &max_num);

	TEL** tel_list = (TEL**)malloc(sizeof(TEL*) * max_num); // max_num�� ��ŭ tel_list�� �����Ҵ�
	if (tel_list == NULL) { // �����Ҵ� ���� ���� üũ
		printf("Not enough memory!");
		return -1;
	}

	int count = 0; // ���� ����ó ����
	int menu;


	while (1) {

		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
		printf("Enter_the_menu_number:");
		scanf("%d", &menu);

		switch (menu) {
		case 1: insert(tel_list, &count, max_num); break;
		case 2: print_all(tel_list, count); break;
		case 3: delete_tel(tel_list, &count); break;
		case 4: find_by_birth(tel_list, count); break;
		case 5: return 0; // ����
		}
	}




	// ----------- �޸� ���� ------------

	for (int i = 0; i < count; i++) {// �� TEL���� ������� �޸� ����
		if (tel_list[i]->name != NULL)
			free(tel_list[i]->name);
		if (tel_list[i]->tel_no != NULL)
			free(tel_list[i]->tel_no);
		if (tel_list[i]->birth != NULL)
			free(tel_list[i]->birth);
	}

	for (int i = 0; i < count; i++) // ���� ����ó ������ŭ tel_list ������ TEL* �޸� ����
		if (tel_list[i] != NULL)
			free(tel_list[i]);

	if(tel_list != NULL) // 2�������� tel_list �޸� ����
		free(tel_list);


	return 0;
}


void insert(TEL** tel_list, int* count, int max_num) {

	// ----------- ����ó�� --------------
	if (*count == max_num) { // ����ó ������ max_num ���� �ʰ��ϸ�
		printf("OVERFLOW\n"); // ���޼��� ���
		return; // �޴��� ���ư�
	}

	// ----------- tel_list �ȿ� ����ó �����Ҵ� ------------

	tel_list[*count] = (TEL*)malloc(sizeof(TEL));
	if (tel_list[*count] == NULL) { // �����Ҵ� ���� ���� üũ
		printf("Not enough memory!");
		return -1;
	}

	char buffer[101]; // ���ڿ��� �ӽ÷� �Է¹��� ����, ũ��� �ι��ڸ� ���� 100����Ʈ

	printf("Name:"); // �̸� �Է�
	scanf("%s", buffer);


	// �Ź� �ڷᰡ ��ϵ� �� ���� ��ü�ڷḦ �������� ����,
	// ���Ե� ��ġ�� ã�� �� ������ �ڷḦ �̵��ϴ� ������� �Ѵ�.

	for (int i = 0; i < *count; i++) {
		if (strcmp(tel_list[i]->name,  buffer) < 0) { // ���� �Է¹��� �̸��� �迭�� ����� �̸�����  
			// ���������� ���ʿ� �־�� �Ѵٸ�
			continue; // �ǳʶٱ�
		}
		else { // �Է¹��� �̸��� �־�� �� ��ġ�� ã����

			// ------------- ����ó�� ������ ���� ���� ------------------

			for (int j = *count - 1; j >= i; j--) { // [i]���� [count - 1]���� �ڷ� ��ĭ�� �б�
				*tel_list[j + 1] = *tel_list[j];
			}
			

			// ------------- name �����Ҵ� �� ���� ---------------

			tel_list[i]->name = (char*)malloc(sizeof(char) * (strlen(buffer) + 1)); // buffer�� �Էµ� ���ڿ��� ���� + 1 ��ŭ �����Ҵ�
			if (tel_list[i]->name == NULL) { // �����Ҵ� ���� ���� üũ
				printf("Not enough memory!");
				return -1;
			}
			strcpy(tel_list[i]->name, buffer); // �̸� ����


			// -------------- tel_no �����Ҵ� �� ���� ------------

			printf("Phone_number:");
			scanf("%s", buffer); // ��ȣ�� ���ۿ� �Է¹���
			tel_list[i]->tel_no = (char*)malloc(sizeof(char) * (strlen(buffer) + 1)); // buffer�� �Էµ� ���ڿ��� ���� + 1 ��ŭ �����Ҵ�
			if (tel_list[i]->tel_no == NULL) { // �����Ҵ� ���� ���� üũ
				printf("Not enough memory!");
				return -1;
			}
			strcpy(tel_list[i]->tel_no, buffer); // ��ȣ ����


			// -------------- birth �����Ҵ� �� ���� ------------

			printf("Birth:");
			scanf("%s", buffer); // ��������� ���ۿ� �Է¹���
			tel_list[i]->birth = (char*)malloc(sizeof(char) * (strlen(buffer) + 1)); // buffer�� �Էµ� ���ڿ��� ���� + 1 ��ŭ �����Ҵ�
			if (tel_list[i]->birth == NULL) { // �����Ҵ� ���� ���� üũ
				printf("Not enough memory!");
				return -1;
			}
			strcpy(tel_list[i]->birth, buffer); // ������� ����


			// ------------ ����ó ���� ���� ------------
			(*count)++;
			printf("<<%d>> \n", *count); // ����ó ���� ���
			return;
		}


	}
	

	// ������ �ڸ��� ã�� ���ߴٸ� �迭�� ���� �ڿ� �����Ҵ� �ϰ� ���� 

	
	// ------------- name �����Ҵ� �� ���� ---------------

	tel_list[*count]->name = (char*)malloc(sizeof(char) * (strlen(buffer) + 1)); // buffer�� �Էµ� ���ڿ��� ���� + 1 ��ŭ �����Ҵ�
	if (tel_list[*count]->name == NULL) { // �����Ҵ� ���� ���� üũ
		printf("Not enough memory!");
		return -1;
	}
	strcpy(tel_list[*count]->name, buffer); // �̸� ����



	// -------------- tel_no �����Ҵ� �� ���� ------------

	printf("Phone_number:");
	scanf("%s", buffer); // ��ȣ�� ���ۿ� �Է¹���
	tel_list[*count]->tel_no = (char*)malloc(sizeof(char) * (strlen(buffer) + 1)); // buffer�� �Էµ� ���ڿ��� ���� + 1 ��ŭ �����Ҵ�
	if (tel_list[*count]->tel_no == NULL) { // �����Ҵ� ���� ���� üũ
		printf("Not enough memory!");
		return -1;
	}
	strcpy(tel_list[*count]->tel_no, buffer); // ��ȣ ����


	
	// -------------- birth �����Ҵ� �� ���� ------------


	printf("Birth:");
	scanf("%s", buffer); // ��������� ���ۿ� �Է¹���
	tel_list[*count]->birth = (char*)malloc(sizeof(char) * (strlen(buffer) + 1)); // buffer�� �Էµ� ���ڿ��� ���� + 1 ��ŭ �����Ҵ�
	if (tel_list[*count]->birth == NULL) { // �����Ҵ� ���� ���� üũ
		printf("Not enough memory!");
		return -1;
	}
	strcpy(tel_list[*count]->birth, buffer); // ������� ����



	// ------------ ����ó ���� ���� ------------

	(*count)++; // ����ó ���� ����
	printf("<<%d>> \n", *count); // ����ó ���� ���
	return;

}

void print_all(TEL** tel_list, int count) {
	if (count == 0) return; // ��ϵ� ����� ������ ������� ����
	for (int i = 0; i < count; i++) // ����ó ���
		printf("%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth);
}

void delete_tel(TEL** tel_list, int* count) {

	if (*count == 0) { // ����� ����ó�� ������ ����
		printf("NO MEMBER\n");
		return;
	}

	char buffer[101]; // �̸��� �Է¹޾� �ӽ÷� ����
	printf("Name:");
	scanf("%s", buffer);

	for (int i = 0; i < *count; i++) {
		if (strcmp(buffer, tel_list[i]->name) == 0) { // ����ó���� ���� �̸��� ã����
			// [i + 1]���� [*count - 1]���� ������ ��ĭ�� ���
			for (int j = i + 1; j < *count; j++) {
				*tel_list[j - 1] = *tel_list[j];
			}
			(*count)--; // ����ó ���� ����
			return;
		}
	}
	// ����ó�� ���� �̸��̸� �޼��� ��� �� �޴��� ����
	printf("NO MEMBER\n");
	return;
}

void find_by_birth(TEL** tel_list, int count) {
	char tmp_month[3] = { '\0' };
	printf("Birth:");
	scanf("%s", &tmp_month); // ���� �� �Է�

	// ��ϵ� ����ó�� ���� ��쿡�� �ٷ� ����
	if (count == 0) return;

	for (int i = 0; i < count; i++) {

		if (tmp_month[1] == '\0') { // ���� ���ڸ������
			if (strncmp(&tel_list[i]->birth[5], tmp_month, 1) == 0) { // ������ ������
				printf("%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth); // ����ó ���
				continue;
			}
		}
		else { // ���� ���ڸ������
			if (strncmp(&tel_list[i]->birth[4], tmp_month, 2) == 0) { // ������ ������
				printf("%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth); // ����ó ���
				continue;
			}
		}
	}
}
