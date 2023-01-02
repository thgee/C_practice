// 7-5

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char ch[6];

	scanf("%s", ch);


	for (int j = 0; j < 5; j++) {
		printf("%s\n", ch);
		char temp = ch[4];

		for (int i = 4; i > 0; i--)
			ch[i] = ch[i - 1];

		ch[0] = temp;
	}

	return 0;
}