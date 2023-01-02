// 7-6

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char ans[4], show[4] = "___";
	char input;
	int cnt = 0;

	scanf("%s", ans);

	for (int i = 0; i < 5; i++) {
		getchar();
		scanf("%c", &input);
		for (int j = 0; j < 3; j++) {
			if (input == ans[j]) {
				show[j] = input;
				cnt++;
			}  
		}
			printf(" %s", show);
			if (cnt == 3) break;
	}

	return 0;
}