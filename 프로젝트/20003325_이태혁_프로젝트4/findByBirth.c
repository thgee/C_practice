#define _CRT_SECURE_NO_WARNINGS
#include "my_func.h"

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
