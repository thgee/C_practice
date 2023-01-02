// 7-7

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int arr[10], in[10] = {0};
	for(int i = 0; i < 10; i++)
	scanf("%d", &arr[i]);


	for (int i = 0; i < 10; i++){
		int cnt = 0;
		if (in[i] > 0) continue;
		for (int j = 0; j < 10; j++) {
			if (arr[i] == arr[j]) {
				cnt++;
				in[j]++;
			}
		}
		printf("%d %d\n", arr[i], cnt);
	}


	return 0;
}