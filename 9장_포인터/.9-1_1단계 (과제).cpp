//_9-1_1단계 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int* MAX(int arr[]);
int* MIN(int arr[]);

int main() {

	int N; // N줄 입력
	int arr[100];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int* max; // 최댓값을 가리키는 포인터
		int* min; // 최솟값을 가리키는 포인터
		int* p = arr;

		while (1) {
			scanf("%d", p);
			if (*p == 0) break; // 0을 입력받으면 탈출
			p++;
		}

		max = MAX(arr); // 최댓값 갱신
		min = MIN(arr); // 최솟값 갱신
		printf("%d %d\n", *max, *min); // 출력
	}
	return 0;
}

int* MAX(int arr[]) {

	int* max = arr; // arr의 최댓값을 가리키는 포인터
	int* p = arr; // arr 을 가리키는 포인터
	while (1) {
		if (*p == 0) break; // 0을 입력받으면 탈출
		if (*p > *max) max = p; // 최댓값 갱신
		p++;
	}
	return max;
}

int* MIN(int arr[]) {

	int* min = arr; // arr의 최솟값을 가리키는 포인터
	int* p = arr; // arr을 가리키는 포인터
	while (1) {
		if (*p == 0) break; // 0을 입력받으면 탈출
		if (*p < *min) min = p; // 최솟값 갱신
		p++;
	}
	return min;
}
