#define _CRT_SECURE_NO_WARNINGS
#include "my_func.h"

void print_all(TEL** tel_list, int count) {
	if (count == 0) return; // 등록된 사람이 없으면 출력하지 않음
	for (int i = 0; i < count; i++) // 연락처 출력
		printf("%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth);
}
