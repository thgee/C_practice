// 10-1 (�߰�)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main() {

	int N;
	char words[20][200];
	int arr[10];

	scanf("%d", &N);

	// �ܾ� �Է�
	for (int i = 0; i < N; i++) {
		scanf("%s", words[i]);
	}


	// ���� �Է�
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		printf("%s ", words[arr[i] - 1]);
	}

	return 0;
}
