// 2차인증 예상문제 4

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
		if (*i > *(i + 1) || i == p + N - 2) { // 현재 원소보다 다음 원소가 더 작거나 문자열의 끝까지 증가하면
			return i; // 현재 원소의 주소를 반환
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