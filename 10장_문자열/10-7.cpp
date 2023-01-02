// 10-7

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int reverse(int N, int* num);
int getLength(char str[]);

int main() {

	int N;
	scanf("%d", &N);

	int num = 0;
	int* p_num = &num;
	N = reverse(N, p_num);

	while (N) {

		switch (N % 10){

		case 1:
			printf("one ");
			break;
		case 2:
			printf("two ");
			break;
		case 3:
			printf("three ");
			break;
		case 4:
			printf("four ");
			break;
		case 5:
			printf("five ");
			break;
		case 6:
			printf("six ");
			break;
		case 7:
			printf("seven ");
			break;
		case 8:
			printf("eight ");
			break;
		case 9:
			printf("nine ");
			break;
		}

		switch (num) {
		case 2:
			if (N % 10 == 0) break;
			printf("TEN ");
			break;
		case 3:
			if (N % 10 == 0) break;
			printf("HUN ");
			break;
		case 4:
			if (N % 10 == 0) break;
			printf("THO ");
			break;

		}
		N /= 10;
		num--;
	}

	return 0;
}


int getLength(char str[]) {
	int len = 0;
	while (1) {
		if (str[len] == '\0') break;
		len++;
	}
	return len;
}
	
int reverse(int N, int* p_num) {
	int res = 0;
	while (N) {
		res *= 10;
		res += N % 10;
		N /= 10;
		(*p_num)++;
	}
	return res;
}
