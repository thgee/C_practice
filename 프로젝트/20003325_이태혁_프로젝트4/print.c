#define _CRT_SECURE_NO_WARNINGS
#include "my_func.h"

void print_all(TEL** tel_list, int count) {
	if (count == 0) return; // ��ϵ� ����� ������ ������� ����
	for (int i = 0; i < count; i++) // ����ó ���
		printf("%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth);
}
