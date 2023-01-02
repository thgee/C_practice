#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int func(int n);

int main() {

	int n;
	scanf("%d", &n);
	printf("%d", func(n));
	return 0;
}


int func(int n){
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return func(n - 1) + func(n - 2);
}