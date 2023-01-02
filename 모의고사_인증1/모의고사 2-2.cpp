// 모의고사 2-2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int input(int* p);
int* sel_next(int* p);
int number(int* p, int* q);

int main() {

	int x[100] = { 0 };

	int N = 0; // -1 제외 원소 갯수
	N = input(x); // 값 입력

	int* end; // 정수의 끝 주소
	for (int* i = x; i < x + N - 1;) {
		end = sel_next(i);
		printf("%d\n", number(i, end)); // i부터 end까지 정수 출력
		i = end;
	}
	



	return 0;
}

int input(int* p) {
	//  배열 x의 시작 주소를 인자로 받아 종료 조건까지 정수를 입력받아 배열에 저장하고,
	//  배열 원소의 개수를 반환한다
	int cnt = 0;
	for (int* i = p;; i++) {
		scanf("%d", i);
		if (*i == -1) break;
		cnt++; // -1제외 원소 갯수 반환
	}
	return cnt;
}

int* sel_next(int* p) {
// 배열의 한 원소의 주소 p를 인자로 받아, p가 가리키는 원소부터 
// 원소 값의 증가 또는 감소가 끝나는 마지막 원소의 주소를 반환 한다.
	
	int* res = NULL;
	int flag = 0; // 1: 올라감 -1: 내려감
	for (int* i = p;; i++) {

		if (*i == -1) { // 끝점
			return i - 1;
		}

		if (flag == 0 && *(i + 1) > *i) { // 초기상태에서 값이 올라가면
			flag = 1;
		}
		if (flag == 1 && *(i + 1) < *i) { // 올라가다가 내려가면
			return i;
		}

		if (flag == 0 && *(i + 1) < *i) { // 초기에서 내려가면
			flag = -1;
		}

		if (flag == -1 && *(i + 1) > *i) { // 내려가다가 올라가면
			return i;
		}
		

	}
}

int number(int* p, int* q) {
//  배열의 두 원소의 주소 p과 q를 인자로 받아, 
//  두 포인터 사이의 한 자리 정수를 모아 하나의 정수로 만들어 반환 한다
	int res = 0;
	for (int* i = p; i <= q; i++) {
		res *= 10; // 자리수 점프
		res += *i; // 일의자리에 더함
	}
	return res;
}
