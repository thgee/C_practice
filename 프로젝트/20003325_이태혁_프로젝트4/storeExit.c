#define _CRT_SECURE_NO_WARNINGS
#include "my_func.h"


void storeExit(TEL** tel_list, int count) {

	FILE* fp = fopen("PHONE_BOOK.txt", "w"); // txt������ �о��
	for (int i = 0; i < count; i++) {
		fprintf(fp, "%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth); // ���Ͽ� tel_list ����
	}

	fclose(fp);


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

	if (tel_list != NULL) // 2�������� tel_list �޸� ����
		free(tel_list);

}
