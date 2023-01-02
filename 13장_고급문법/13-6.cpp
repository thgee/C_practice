#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ABC(int(*p)[20], int k1, int k2);

void main() {
	int N;
	scanf("%d", &N);
	int arr[20][20];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			ABC(arr, i, j);
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}
	

}


void ABC(int(*p)[20], int k1, int k2) {
			(*(p + k1))[k2] = k1 +k2;
}
