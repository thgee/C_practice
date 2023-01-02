// 9-2_2단계 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int passengerN(int n);
void rebooking(int* arr);
int changeseat(int* arr);

int main() {

	int N; // 승객의 수
	scanf("%d", &N);

	// 승객이 부족할 시
	if (passengerN(N) == -1) printf("%d", -1);

	// 정상운행 시
	else {
		printf("%d\n", 0);

		int arr[21] = { 0 }; // 예약번호 배열 초기화

		// 예약번호 입력
		for (int* p = arr; p < arr + N; p++)
			scanf("%d", p);

		rebooking(arr); // 좌석 재할당

		// 출력
		for (int* p = arr; p < arr + N; p++)
			printf("%d ", *p);
	}

	return 0;
}

int passengerN(int n) {
	if (n < 5) return -1; // 승객이 5명 미만이면 -1 반환
	return 0;
}

void rebooking(int* arr) {

	int* p = arr; // arr을 가리키는 포인터 p, q
	int* q = arr;

	for (p = arr; p < arr + 21; p++) {
		int cnt = 0;
		for (q = arr; q < arr + 21; q++) {
			if (*p == *q) cnt++; // 중복이 발생하면 cnt 증가
			if (cnt > 1) {
				*q = changeseat(arr); // 새로운 좌석으로 변경
				cnt = 1; // cnt 초기화
			}
		}
	}

}


int changeseat(int* arr) {
	for (int i = 1; i <= 21; i++) {
	int cnt = 0;
		for (int* p = arr; p < arr + 21; p++) {
			if (*p == i) cnt++; // 21까지 순환하면서 배열에 있는 숫자이면 cnt 증가
		}
		if (cnt == 0) return i; // 배열에 한번도 나오지 않은 숫자이면 그 숫자를 반환
	}
	// 1~21까지 중복없이 예약될 경우 -1 반환
	return -1; 
}

