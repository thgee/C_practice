// 8-10

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;

void die1(int);
void die2(int, int);
void die3(int, int, int); 


void die1(int x) {
	for (int y = 1; y <= 6; y++) {
		die2(x, y);
	}
}

void die2(int x, int y) {
	for (int z = 1; z <= 6; z++) {
		die3(x, y, z);
	}
}

void die3(int x, int y, int z) {
	if(x + y + z == N)
		printf("%d %d %d\n", x, y, z);
}


int main() {

	scanf("%d", &N);
	for (int x = 1; x <= 6; x++)
		die1(x);

	return 0;
}
