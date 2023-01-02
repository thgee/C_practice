// 7-15(±‚√ )

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char arr[11];
	scanf("%s", arr);


	for (int i = 0; i < 10; i++) {
	int cnt = 0;
		for (int j = 0; j < 10; j++) {
			if (arr[i] == arr[j]) {
				cnt++;
			}
		}
		if (cnt == 1) printf(" %c", arr[i]);
	}

	return 0;
}