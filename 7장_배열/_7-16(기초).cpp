// 7-16(±‚√ )

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int N;
	scanf("%d", &N);
	getchar();
	char ch[11];
	int arr[11];
	for(int i = 0; i < N; i++)
		scanf("%c", &ch[i]);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++) {
		int idx = arr[i] % N;
		printf("x[%d%%%d]=x[%d]=%c\n", arr[i], N, idx, ch[idx]);
	}


	return 0;
}