#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double factorial(int a);

int main() {

	int n;
	scanf("%d", &n);
	double res = 0;
	for (int i = 1; i <= n; i++)
		res += 1.0 / factorial(i);
	
	printf("%.6lf", res+1);

	return 0;
}


double factorial(int a) {
	if (a == 1) return a;
	else return a * factorial(a - 1);
}