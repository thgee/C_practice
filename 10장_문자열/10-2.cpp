// 10-2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int N;
	char ch[10];
	scanf("%d", &N);
	
	int	i = 0;
	while (N) {
		ch[i] = (char)(N % 10) + '0';
		N /= 10;
		i++;
	}

	printf("%s", ch);

	return 0;
}