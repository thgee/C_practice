#define _CRT_SECURE_NO_WARNINGS
#include "my_func.h"


void sort(TEL** tel_list, int count) {

	// �Ź� �ڷᰡ ��ϵ� �� ���� ��ü�ڷḦ �������� ����,
	// �ϴ� �迭�� �� �ڿ� ������ ��
	// ���Ե� ��ġ�� ã�� �� ������ �ڷḦ �̵��ϴ� ������� �Ѵ�.

	TEL* temp = tel_list[count - 1]; // ��� ������ ����ó�� temp�� �ӽ÷� ����
	for (int i = 0; i < count - 1; i++) { // ����ó�� �ϳ��� Ž��

		if (strcmp(tel_list[i]->name, tel_list[count - 1]->name) < 0) { // ��� ������ ����ó���� ���������� �����ٸ�
			continue; // �ǳʶٱ�
		}
		else if (strcmp(tel_list[i]->name, tel_list[count - 1]->name) > 0) { // ���ԵǾ�� �� ��ġ�� ã����

			// ------------- ����ó�� ������ ���� ���� ------------------

			for (int j = count - 2; j >= i; j--) { // [i]���� [count - 1]���� �ڷ� ��ĭ�� �б�
				tel_list[j + 1] = tel_list[j];
			}
			tel_list[i] = temp; // ����ó ����
			break;
		}
	}
}