// 7-12(±‚√ )

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	float arr[10];
		int rank[10] = { 0 };
	for (int i = 0; i < 10; i++)
		scanf("%f", &arr[i]);
	
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (arr[i] > arr[j]) rank[i]++;

	for (int i = 0; i < 10; i++) {
		printf(" %d", rank[i]);
	}
			


	return 0;
}
