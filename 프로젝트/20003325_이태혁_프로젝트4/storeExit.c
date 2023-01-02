#define _CRT_SECURE_NO_WARNINGS
#include "my_func.h"


void storeExit(TEL** tel_list, int count) {

	FILE* fp = fopen("PHONE_BOOK.txt", "w"); // txt파일을 읽어옴
	for (int i = 0; i < count; i++) {
		fprintf(fp, "%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth); // 파일에 tel_list 저장
	}

	fclose(fp);


	// ----------- 메모리 해제 ------------

	for (int i = 0; i < count; i++) {// 각 TEL마다 멤버변수 메모리 해제
		if (tel_list[i]->name != NULL)
			free(tel_list[i]->name);
		if (tel_list[i]->tel_no != NULL)
			free(tel_list[i]->tel_no);
		if (tel_list[i]->birth != NULL)
			free(tel_list[i]->birth);
	}

	for (int i = 0; i < count; i++) // 현재 연락처 개수만큼 tel_list 내부의 TEL* 메모리 해제
		if (tel_list[i] != NULL)
			free(tel_list[i]);

	if (tel_list != NULL) // 2중포인터 tel_list 메모리 해제
		free(tel_list);

}
