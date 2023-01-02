// ����ó ���� ���α׷�

#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUM 100

#include <stdio.h>
#include <string.h>

struct tel {
	char name[21]; // �̸�
	char tel_no[16]; // ��ȭ��ȣ
	char birth[9]; // �������
}person;

void insert(struct tel tel_list[], int* count);
void print_all(struct tel tel_list[], int count);
void delete_tel(struct tel tel_list[], int* count);
void find_by_birth(struct tel tel_list[], int count);

int main() {

	struct tel tel_list[MAX_NUM]; // �ִ� 100�� ����
	int count = 0;
	int menu;


	while (1) {

		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
		printf("Enter_the_menu_number:");
		scanf("%d", &menu);

		switch (menu) {
		case 1: insert(tel_list, &count); break;
		case 2: print_all(tel_list, count); break;
		case 3: delete_tel(tel_list, &count); break;
		case 4: find_by_birth(tel_list, count); break;
		case 5: return 0; // ����
		}
	}

	return 0;
}


void insert(struct tel tel_list[], int* count) {

	// ----------- ����ó�� --------------
	if (*count == 100) { // ����ó ������ 100���� �Ѿ��
		printf("OVERFLOW\n"); // ���޼��� ���
		return; // �޴��� ���ư�
	}

	char tmp_name[21]; // �Է¹��� name�� �ӽ÷� ����

	printf("Name:"); // �̸� �Է�
	scanf("%s", tmp_name);


	// �Ź� �ڷᰡ ��ϵ� �� ���� ��ü�ڷḦ �������� ����,
	// ���Ե� ��ġ�� ã�� �� ������ �ڷḦ �̵��ϴ� ������� �Ѵ�.

	for (int i = 0; i < *count; i++) {
		if (strcmp(tel_list[i].name, tmp_name) < 0) { // ���� �Է¹��� �̸��� �迭�� ����� �̸�����  
			// ���������� ���ʿ� �־�� �Ѵٸ�
			continue; // �ǳʶٱ�
		}
		else { // �Է¹��� �̸��� �־�� �� ��ġ�� ã����

			// ------------- ����ó ��� ------------------
			for (int j = *count - 1; j >= i; j--) { // [i]���� [count - 2]���� �ڷ� ��ĭ�� �б�
				tel_list[j + 1] = tel_list[j];
			}
			strcpy(tel_list[i].name, tmp_name); // �̸� ����
			printf("Phone_number:"); scanf("%s", tel_list[i].tel_no); // ��ȣ ����
			printf("Birth:");	scanf("%s", tel_list[i].birth); // ������� ����
			(*count)++;
			printf("<<%d>> \n", *count); // ����ó ���� ���
			return;
		}


	}
	// ������ �ڸ��� ã�� ���ߴٸ� ���� �ڿ� ���� 
	strcpy(tel_list[*count].name, tmp_name); // �̸� ����
	printf("Phone_number:"); scanf("%s", tel_list[*count].tel_no); // ��ȣ ����
	printf("Birth:");	scanf("%s", tel_list[*count].birth); // ������� ����
	(*count)++; // ����ó ���� ����
	printf("<<%d>> \n", *count); // ����ó ���� ���
	return;

}

void print_all(struct tel tel_list[], int count) {
	if (count == 0) return; // ��ϵ� ����� ������ ������� ����
	for (int i = 0; i < count; i++) // ����ó ���
		printf("%s %s %s\n", tel_list[i].name, tel_list[i].tel_no, tel_list[i].birth);
}

void delete_tel(struct tel tel_list[], int* count) {

	if (*count == 0) { // ����� ����ó�� ������ ����
		printf("NO MEMBER\n");
		return;
	}

	char tmp_name[21]; // �̸��� �Է¹޾� �ӽ÷� ����
	printf("Name:");
	scanf("%s", tmp_name);

	for (int i = 0; i < *count; i++) {
		if (strcmp(tmp_name, tel_list[i].name) == 0) { // ����ó���� ���� �̸��� ã����
			// [i + 1]���� [*count - 1]���� ������ ��ĭ�� ���
			for (int j = i + 1; j < *count; j++) {
				tel_list[j - 1] = tel_list[j];
			}
			(*count)--; // ����ó ���� ����
			return;
		}
	}
	// ����ó�� ���� �̸��̸� �޼��� ��� �� �޴��� ����
	printf("NO MEMBER\n");
	return;
}

void find_by_birth(struct tel tel_list[], int count) {
	char tmp_month[3] = { '\0' };
	printf("Birth:");
	scanf("%s", &tmp_month); // ���� �� �Է�
	
	// ��ϵ� ����ó�� ���� ��쿡�� �ٷ� ����
	if (count == 0) return;

	for (int i = 0; i < count; i++) {

		if (tmp_month[1] == '\0') { // ���� ���ڸ������
			if (strncmp(&tel_list[i].birth[5], tmp_month, 1) == 0) { // ������ ������
				printf("%s %s %s\n", tel_list[i].name, tel_list[i].tel_no, tel_list[i].birth); // ����ó ���
				continue;
			}
		}
		else { // ���� ���ڸ������
			if (strncmp(&tel_list[i].birth[4], tmp_month, 2) == 0) { // ������ ������
				printf("%s %s %s\n", tel_list[i].name, tel_list[i].tel_no, tel_list[i].birth); // ����ó ���
				continue;
			}
		}
	}
}
