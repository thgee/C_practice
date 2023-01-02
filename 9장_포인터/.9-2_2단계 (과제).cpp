// 9-2_2�ܰ� (����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int passengerN(int n);
void rebooking(int* arr);
int changeseat(int* arr);

int main() {

	int N; // �°��� ��
	scanf("%d", &N);

	// �°��� ������ ��
	if (passengerN(N) == -1) printf("%d", -1);

	// ������� ��
	else {
		printf("%d\n", 0);

		int arr[21] = { 0 }; // �����ȣ �迭 �ʱ�ȭ

		// �����ȣ �Է�
		for (int* p = arr; p < arr + N; p++)
			scanf("%d", p);

		rebooking(arr); // �¼� ���Ҵ�

		// ���
		for (int* p = arr; p < arr + N; p++)
			printf("%d ", *p);
	}

	return 0;
}

int passengerN(int n) {
	if (n < 5) return -1; // �°��� 5�� �̸��̸� -1 ��ȯ
	return 0;
}

void rebooking(int* arr) {

	int* p = arr; // arr�� ����Ű�� ������ p, q
	int* q = arr;

	for (p = arr; p < arr + 21; p++) {
		int cnt = 0;
		for (q = arr; q < arr + 21; q++) {
			if (*p == *q) cnt++; // �ߺ��� �߻��ϸ� cnt ����
			if (cnt > 1) {
				*q = changeseat(arr); // ���ο� �¼����� ����
				cnt = 1; // cnt �ʱ�ȭ
			}
		}
	}

}


int changeseat(int* arr) {
	for (int i = 1; i <= 21; i++) {
	int cnt = 0;
		for (int* p = arr; p < arr + 21; p++) {
			if (*p == i) cnt++; // 21���� ��ȯ�ϸ鼭 �迭�� �ִ� �����̸� cnt ����
		}
		if (cnt == 0) return i; // �迭�� �ѹ��� ������ ���� �����̸� �� ���ڸ� ��ȯ
	}
	// 1~21���� �ߺ����� ����� ��� -1 ��ȯ
	return -1; 
}

