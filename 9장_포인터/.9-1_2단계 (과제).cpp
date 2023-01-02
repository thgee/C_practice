//_9-1_2�ܰ� (����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int* MAX(int arr[]);
int* MIN(int arr[]);

int main() {

	int N; // N�� �Է�
	int arr[100];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int* max; // �ִ��� ����Ű�� ������
		int* min; // �ּڰ��� ����Ű�� ������
		int* p = arr;

		while (1) {
			scanf("%d", p);
			if (*p == 0) break; // 0�� �Է¹����� Ż��
			p++;
		}

		max = MAX(arr); // �ִ� ����
		min = MIN(arr); // �ּڰ� ����
		int* ps = max < min ? max : min; // �ִ񰪰� �ּڰ��� �� ���ʿ� ��ġ�ϴ� ������ �ּ� ����
		int* pe = max < min ? min : max; // �ִ񰪰� �ּڰ��� �� ���ʿ� ��ġ�ϴ� ������ �ּ� ����
		if (ps == pe || pe == ps + 1) printf("none"); // ����� ���� ������ none ���
		else
			for (int *q = ps + 1; q < pe; q++)
				printf("%d ", *q); // �ִ񰪰� �ּڰ� ������ �迭 ���
	}
	return 0;
}

int* MAX(int arr[]) {

	int* max = arr; // arr�� �ִ��� ����Ű�� ������
	int* p = arr; // arr �� ����Ű�� ������
	while (1) {
		if (*p == 0) break; // 0�� �Է¹����� Ż��
		if (*p > *max) max = p; // �ִ� ����
		p++;
	}
	return max;
}

int* MIN(int arr[]) {

	int* min = arr; // arr�� �ּڰ��� ����Ű�� ������
	int* p = arr; // arr�� ����Ű�� ������
	while (1) {
		if (*p == 0) break; // 0�� �Է¹����� Ż��
		if (*p < *min) min = p; // �ּڰ� ����
		p++;
	}
	return min;
}
