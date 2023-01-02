// 9-4-1 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void prtHighLow(int* a, int* b, int n, int  m); // 최고점수, 최저점수를 출력하는 함수

int main() {

	int n = 0, m = 0; // a배열의 원소 갯수 n, b배열의 원소 갯수 m
	int a[11], b[11];
	
	int* p_a = a, * p_b = b; // 각각 a와 b의 시작주소를 가리키는 포인터

	//-------------------- input -------------------
	while (true) { // 무한루프
		scanf("%d", p_a);
		if (*p_a == -1) break; // -1을 입력받으면 탈출
		n++; // 원소 갯수 증가
		p_a++;
	}
	while (true) { // 무한루프
		scanf("%d", p_b);
		if (*p_b == -1) break; // -1을 입력받으면 탈출
		m++; // 원소 갯수 증가
		p_b++;
	}
	//-----------------------------------------------

	printf("%d %d\n", n, m); // 출력
	prtHighLow(a, b, n, m); // 출력

	return 0;
}


void prtHighLow(int* a, int* b,int  n,int  m) {
	
	int high = 0, low = 100; // 최고점수, 최저점수 초기화
	for (int* p_a = a; p_a < a + n; p_a++) {
		if (high < *p_a) high = *p_a; // 최고점수 갱신
		if (low > *p_a) low = *p_a; // 최저점수 갱신
	}
		for (int* p_b = b; p_b < b + m; p_b++) {
		if (high < *p_b) high = *p_b; // 최고점수 갱신
		if (low > *p_b) low = *p_b; // 최저점수 갱신
	}

		printf("%d %d", high, low);

}