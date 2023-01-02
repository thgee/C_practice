// 9-4-2 (����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sort(int* p, int n); // �����Լ�

int main() {

	int n = 0, m = 0; // a�迭�� ���� ���� n, b�迭�� ���� ���� m
	int a[11], b[11];
	int tot[20]; // a�迭�� b�迭�� ��ģ �迭

	int* p_a = a, * p_b = b; // ���� a�� b�� �����ּҸ� ����Ű�� ������

	//-------------------- input -------------------
	while (1) { //
		scanf("%d", p_a);
		if (*p_a == -1) break; // -1�� �Է¹����� Ż��
		n++; // ���� ���� ����
		p_a++;
	}
	while (1) { // ���ѷ���
		scanf("%d", p_b);
		if (*p_b == -1) break; // -1�� �Է¹����� Ż��
		m++; // ���� ���� ����
		p_b++;
	}

	
	//----------------- �迭 ��ġ�� ------------------------
	int* p_tot = tot;
	int len_tot = 0; // tot�迭�� ���� ����
	for (int* p_a = a; p_a < a + n; p_a++, p_tot++) { // tot �迭�� a �迭�� ����
		*p_tot = *p_a;
		len_tot++; // ���� ���� ����
	}
	for (int* p_b = b; p_b < b + m; p_b++, p_tot++) { // tot �迭�� b �迭�� ����
		*p_tot = *p_b;
		len_tot++; // ���� ���� ����
	}

	sort(tot, len_tot);


	for (int* p_tot = tot; p_tot < tot + n; p_tot++)
		printf("%d ", *p_tot); // ���� ���� �������� n�� ���

	printf("\n");

	for (int* p_tot = tot + len_tot - 1; p_tot >= tot + len_tot - m; p_tot--)
		printf("%d ", *p_tot); // ���� ���� �������� m�� ���


	return 0;
}


void sort(int* p, int n) { // �������� ���� (��������)

	for (int* i = p; i < p + n - 1; i++) {
		int* max = i; // ���� ū ���Ҹ� ����� ������
		for (int* j = max; j < p + n; j++) {
			if (*max < *j) max = j; // max�� ����Ű�� ������ ū���� ������ max�� ����
		}
		int tmp = *max; // ����
		*max = *i;
		*i = tmp;
	}
}