// 7-2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char arr[8];
	char cat[4] = "cat";
	scanf("%s", arr);
	int cnt = 0;
	for (int i = 0, j = 0; i < 7; i++) {
		if (arr[i] == cat[j]) j++;
		else j = 0;
		if (j == 3) {
			cnt++;
			j = 0;
		}
	}

	printf("%d", cnt);

		return 0;
}