// 모의고사 1-1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(int* p, int M);
int* sel_max(int* p, int M);
void output(int* p, int N);



int main(void) {
	int in[100], out[100], * max, i, N, M;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		input(in, M);
		max = sel_max(in, M);
		out[i] = *max;
	}
	output(out, N);
	return 0;
}


void input(int* p, int M) {
	//p는 배열의 시작 주소이며, 정수 M개를 입력받아 p가 가리키는 배열에 저장한다.
	for (int* i = p; i < p + M; i++) {
		scanf("%d", i);
	}

}

int* sel_max(int* p, int M) {
	int max_cnt = 0;
	int* p_max = NULL;
	for (int* i = p; i < p + M; i++) {
		int rep_cnt = 0;
		for (int* j = p; j < p + M; j++) {
			if (*i == *j) {
				rep_cnt++;
			}
		}
		if (rep_cnt > max_cnt) {
			max_cnt = rep_cnt;
			p_max = i;

		}
	}
	return p_max;
}


void output(int* p, int N) {
	//p는 배열의 시작 주소이며, 배열에 저장된 정수 N개를 출력한다.

	for (int* i = p; i < p + N; i++)
		printf(" %d", *i);

}
