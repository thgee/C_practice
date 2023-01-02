// ���ǰ�� 2-2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int input(int* p);
int* sel_next(int* p);
int number(int* p, int* q);

int main() {

	int x[100] = { 0 };

	int N = 0; // -1 ���� ���� ����
	N = input(x); // �� �Է�

	int* end; // ������ �� �ּ�
	for (int* i = x; i < x + N - 1;) {
		end = sel_next(i);
		printf("%d\n", number(i, end)); // i���� end���� ���� ���
		i = end;
	}
	



	return 0;
}

int input(int* p) {
	//  �迭 x�� ���� �ּҸ� ���ڷ� �޾� ���� ���Ǳ��� ������ �Է¹޾� �迭�� �����ϰ�,
	//  �迭 ������ ������ ��ȯ�Ѵ�
	int cnt = 0;
	for (int* i = p;; i++) {
		scanf("%d", i);
		if (*i == -1) break;
		cnt++; // -1���� ���� ���� ��ȯ
	}
	return cnt;
}

int* sel_next(int* p) {
// �迭�� �� ������ �ּ� p�� ���ڷ� �޾�, p�� ����Ű�� ���Һ��� 
// ���� ���� ���� �Ǵ� ���Ұ� ������ ������ ������ �ּҸ� ��ȯ �Ѵ�.
	
	int* res = NULL;
	int flag = 0; // 1: �ö� -1: ������
	for (int* i = p;; i++) {

		if (*i == -1) { // ����
			return i - 1;
		}

		if (flag == 0 && *(i + 1) > *i) { // �ʱ���¿��� ���� �ö󰡸�
			flag = 1;
		}
		if (flag == 1 && *(i + 1) < *i) { // �ö󰡴ٰ� ��������
			return i;
		}

		if (flag == 0 && *(i + 1) < *i) { // �ʱ⿡�� ��������
			flag = -1;
		}

		if (flag == -1 && *(i + 1) > *i) { // �������ٰ� �ö󰡸�
			return i;
		}
		

	}
}

int number(int* p, int* q) {
//  �迭�� �� ������ �ּ� p�� q�� ���ڷ� �޾�, 
//  �� ������ ������ �� �ڸ� ������ ��� �ϳ��� ������ ����� ��ȯ �Ѵ�
	int res = 0;
	for (int* i = p; i <= q; i++) {
		res *= 10; // �ڸ��� ����
		res += *i; // �����ڸ��� ����
	}
	return res;
}
