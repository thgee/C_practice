// 9-2_1단계 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int passengerN(int n);

int main() {

	int N; // 승객의 수
	scanf("%d", &N);

	// 승객이 부족할 시
	if (passengerN(N) == -1) printf("%d", -1);

	// 정상운행 시
	else {

		int arr[21];

		// 예약번호 입력
		for (int* p = arr; p < arr + N; p++)
			scanf("%d", p);

		int cnt_rep[21] = { 0 }; // 출력 했는지 안했는지 확인하는 배열
		int* p_cnt_rep = cnt_rep;
		int cnt_norep = 0; // 중복이 하나도 없는 경우를 판단하기 위함

		for (int* p = arr; p < arr + N; p++) {
			int cnt = 0; // 중복 횟수
			for (int* q = arr; q < arr + N; q++) {
				// 중복이 발생하면 cnt의 해당 중복값 인덱스의 원소가 증가함
				if (*p == *q) cnt++;
			}
			if (cnt > 1 && *(p_cnt_rep + *p) == 0) { // 중복이면서 출력을 한번도 안한 숫자를 출력
				printf("%d %d\n", *p, cnt);
				*(p_cnt_rep + *p) += 1; // 출력하고 나면 cnt배열의 *p인덱스 값 증가
				cnt_norep++;
			}
		}
		// 중복된 예약이 하나도 없으면 0 출력
		if (cnt_norep == 0) printf("%d", 0);
	}


	return 0;
}

int passengerN(int n) {
	if (n < 5) return -1; // 승객이 5명 미만이면 -1 반환
	return 0;
}
