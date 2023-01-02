// 9-4-1 (����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void prtHighLow(int* a, int* b, int n, int  m); // �ְ�����, ���������� ����ϴ� �Լ�

int main() {

	int n = 0, m = 0; // a�迭�� ���� ���� n, b�迭�� ���� ���� m
	int a[11], b[11];
	
	int* p_a = a, * p_b = b; // ���� a�� b�� �����ּҸ� ����Ű�� ������

	//-------------------- input -------------------
	while (true) { // ���ѷ���
		scanf("%d", p_a);
		if (*p_a == -1) break; // -1�� �Է¹����� Ż��
		n++; // ���� ���� ����
		p_a++;
	}
	while (true) { // ���ѷ���
		scanf("%d", p_b);
		if (*p_b == -1) break; // -1�� �Է¹����� Ż��
		m++; // ���� ���� ����
		p_b++;
	}
	//-----------------------------------------------

	printf("%d %d\n", n, m); // ���
	prtHighLow(a, b, n, m); // ���

	return 0;
}


void prtHighLow(int* a, int* b,int  n,int  m) {
	
	int high = 0, low = 100; // �ְ�����, �������� �ʱ�ȭ
	for (int* p_a = a; p_a < a + n; p_a++) {
		if (high < *p_a) high = *p_a; // �ְ����� ����
		if (low > *p_a) low = *p_a; // �������� ����
	}
		for (int* p_b = b; p_b < b + m; p_b++) {
		if (high < *p_b) high = *p_b; // �ְ����� ����
		if (low > *p_b) low = *p_b; // �������� ����
	}

		printf("%d %d", high, low);

}