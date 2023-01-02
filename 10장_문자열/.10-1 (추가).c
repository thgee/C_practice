// 10-1 (추가)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main() {

	int N;
	char words[20][200];
	int arr[10];

	scanf("%d", &N);

	// 단어 입력
	for (int i = 0; i < N; i++) {
		scanf("%s", words[i]);
	}


	// 숫자 입력
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		printf("%s ", words[arr[i] - 1]);
	}

	return 0;
}
