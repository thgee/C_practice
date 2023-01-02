// 7-7(±‚√ )

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int arr[10], res[10];
	
	for(int i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	
	int idx = 0;
	for (int i = 0; i < 10; i++) {
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) cnt++;
		}
		if (cnt == 0) res[idx++] = arr[i];
	}

	for (int i = 0; i < idx; i++) {
		printf(" %d", res[i]);
	}
	

	return 0;
}