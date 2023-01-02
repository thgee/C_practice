// 9-11
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void strcopy(char A[], char B[]);

int main() {

	char A[6], B[6];
	for (char* p = A; p < A + 6; p++)
		scanf("%c", p);

	strcopy(A, B);

	for (char* p = B; p < B + 6; p++)
		printf("%c", *p);

	return 0;
}

void strcopy(char A[], char B[]) {
	for (char* p = A, *q = B; p < A + 6; p++, q++)
		*q = *p;
}
