// 9-4-2 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sort(int* p, int n); // 정렬함수

int main() {

	int n = 0, m = 0; // a배열의 원소 갯수 n, b배열의 원소 갯수 m
	int a[11], b[11];
	int tot[20]; // a배열과 b배열을 합친 배열

	int* p_a = a, * p_b = b; // 각각 a와 b의 시작주소를 가리키는 포인터

	//-------------------- input -------------------
	while (1) { //
		scanf("%d", p_a);
		if (*p_a == -1) break; // -1을 입력받으면 탈출
		n++; // 원소 갯수 증가
		p_a++;
	}
	while (1) { // 무한루프
		scanf("%d", p_b);
		if (*p_b == -1) break; // -1을 입력받으면 탈출
		m++; // 원소 갯수 증가
		p_b++;
	}

	
	//----------------- 배열 합치기 ------------------------
	int* p_tot = tot;
	int len_tot = 0; // tot배열의 원소 갯수
	for (int* p_a = a; p_a < a + n; p_a++, p_tot++) { // tot 배열에 a 배열을 넣음
		*p_tot = *p_a;
		len_tot++; // 원소 갯수 층가
	}
	for (int* p_b = b; p_b < b + m; p_b++, p_tot++) { // tot 배열에 b 배열을 넣음
		*p_tot = *p_b;
		len_tot++; // 원소 갯수 층가
	}

	sort(tot, len_tot);


	for (int* p_tot = tot; p_tot < tot + n; p_tot++)
		printf("%d ", *p_tot); // 가장 높은 점수부터 n개 출력

	printf("\n");

	for (int* p_tot = tot + len_tot - 1; p_tot >= tot + len_tot - m; p_tot--)
		printf("%d ", *p_tot); // 가장 낮은 점수부터 m개 출력


	return 0;
}


void sort(int* p, int n) { // 내림차순 정렬 (선택정렬)

	for (int* i = p; i < p + n - 1; i++) {
		int* max = i; // 가장 큰 원소를 기억할 포인터
		for (int* j = max; j < p + n; j++) {
			if (*max < *j) max = j; // max가 가리키는 값보다 큰값이 있으면 max를 갱신
		}
		int tmp = *max; // 스왑
		*max = *i;
		*i = tmp;
	}
}