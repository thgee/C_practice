// ����ó ���� ���α׷�
#define _CRT_SECURE_NO_WARNINGS

#include "my_func.h"

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
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFile><6.Exit>\n");
		printf("Enter_the_menu_number:");
		scanf("%d", &menu);

		switch (menu) {
		case 1: insert(tel_list, &count, max_num); break;
		case 2: print_all(tel_list, count); break;
		case 3: delete_tel(tel_list, &count); break;
		case 4: find_by_birth(tel_list, count); break;
		case 5: RegFromFile(tel_list, &count, max_num); break;
		case 6: storeExit(tel_list, count); return 0;
		}
	}
}
