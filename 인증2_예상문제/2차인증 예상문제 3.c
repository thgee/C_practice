// 2차인증 예상문제 3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct person {
	char name[11];
	int scr1, scr2;
	double tot;
};

void swap(struct person* p, struct person* q);

int main() {

	struct person arr[100];
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s %d %d", arr[i].name, &arr[i].scr1, &arr[i].scr2);
		arr[i].tot = arr[i].scr1 * 8 + arr[i].scr2 * 2;
		arr[i].tot /= 10;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (arr[j].tot < arr[j + 1].tot)
				swap(&arr[j], &arr[j + 1]);
		}
	}

	for(int i = 0; i < M; i++)
		printf("%s %.1lf\n", arr[i].name, arr[i].tot);

	return 0;
}

void swap(struct person* p, struct person* q){
	struct person tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}
