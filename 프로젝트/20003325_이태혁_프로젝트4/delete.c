
#define _CRT_SECURE_NO_WARNINGS
#include "my_func.h"

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
