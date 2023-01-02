// 8-14

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_prime(int x);
int next_prime(int x);


int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		n = next_prime(n);
		printf(" %d", n);
	}
	return 0;
}

int is_prime(int x) {
	
	int res = 0;
	int cnt = 2;
	for (int i = 2; i < x; i++) {
		if (x % i != 0) cnt++;
	}
	if (cnt == x) res = 1;
	return res;
}


int next_prime(int x) {

	int minPrime = x + 1;
	while (1) {
		if (is_prime(minPrime)) break;
		minPrime++;
	}
	return minPrime;
}