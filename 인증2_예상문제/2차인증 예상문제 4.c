// 2������ ������ 4

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int input(int* p);
	 int* sel_next(int* p, int N, int M);
	int number(int* p, int* q);

int main() {

	int arr[100];
	int M;
	int num = input(arr);
	scanf("%d", &M);
	int* start, *end;
	start = arr + M;
		end = sel_next(arr, num, M);
	int res = number(start, end);
	printf("%d", res);
}

int input(int* p) {
	int num = 0;
	for(int* i = p; ; i++){
		scanf("%d", i);
		num++;
			if (*i == -1)
				break;
	}
	return num;
}
int* sel_next(int* p, int N, int M) {
	for (int* i = p + M; i < p + N - 1; i++) {
		if (*i > *(i + 1) || i == p + N - 2) { // ���� ���Һ��� ���� ���Ұ� �� �۰ų� ���ڿ��� ������ �����ϸ�
			return i; // ���� ������ �ּҸ� ��ȯ
		}
	}
}

int number(int* p, int* q) {
	int res = 0;
	for (int* i = p; i <= q; i++) {
		res *= 10;
		res += *i;
	}
	return res;
}