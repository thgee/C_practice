// 8-11

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ans[3];


int count_strike(int a, int b, int c) {
	int strike = 0;

	if (a == ans[0]) strike++;
	if (b == ans[1]) strike++;
	if (c == ans[2]) strike++;

		return strike;
}

int count_ball(int a, int b, int c) {
	int ball = 0;

	if (ans[0] == b || ans[0] == c) ball++;
	if (ans[1] == c || ans[1] == a) ball++;
	if (ans[2] == a || ans[2] == b) ball++;

	return ball;
}

int main() {


	for (int i = 0; i < 3; i++)
		scanf("%d", &ans[i]);

	int strike, ball;
	int a, b, c;

	while (1) {

		scanf("%d%d%d", &a, &b, &c);
		strike = count_strike(a, b, c);
		ball = count_ball(a, b, c);
		printf("%dS%dB\n", strike, ball);
		if (strike == 3) break;
	}

	return 0;
}
