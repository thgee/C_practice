// 9-2_1�ܰ� (����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int passengerN(int n);

int main() {

	int N; // �°��� ��
	scanf("%d", &N);

	// �°��� ������ ��
	if (passengerN(N) == -1) printf("%d", -1);

	// ������� ��
	else {

		int arr[21];

		// �����ȣ �Է�
		for (int* p = arr; p < arr + N; p++)
			scanf("%d", p);

		int cnt_rep[21] = { 0 }; // ��� �ߴ��� ���ߴ��� Ȯ���ϴ� �迭
		int* p_cnt_rep = cnt_rep;
		int cnt_norep = 0; // �ߺ��� �ϳ��� ���� ��츦 �Ǵ��ϱ� ����

		for (int* p = arr; p < arr + N; p++) {
			int cnt = 0; // �ߺ� Ƚ��
			for (int* q = arr; q < arr + N; q++) {
				// �ߺ��� �߻��ϸ� cnt�� �ش� �ߺ��� �ε����� ���Ұ� ������
				if (*p == *q) cnt++;
			}
			if (cnt > 1 && *(p_cnt_rep + *p) == 0) { // �ߺ��̸鼭 ����� �ѹ��� ���� ���ڸ� ���
				printf("%d %d\n", *p, cnt);
				*(p_cnt_rep + *p) += 1; // ����ϰ� ���� cnt�迭�� *p�ε��� �� ����
				cnt_norep++;
			}
		}
		// �ߺ��� ������ �ϳ��� ������ 0 ���
		if (cnt_norep == 0) printf("%d", 0);
	}


	return 0;
}

int passengerN(int n) {
	if (n < 5) return -1; // �°��� 5�� �̸��̸� -1 ��ȯ
	return 0;
}
