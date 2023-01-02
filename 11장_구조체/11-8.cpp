// 11 - 8

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct complex {
	float real;
	float img;
};

struct complex add(struct complex num1, struct complex num2);
	

int main() {



	struct complex num1, num2;
	scanf("%f%f", &num1.real, &num1.img);
	scanf("%f%f", &num2.real, &num2.img);
	struct complex res = add(num1, num2);
	printf("%.1f + %.1fi", res.real, res.img);
	return 0;
}

struct complex add(struct complex num1, struct complex num2) {
	struct complex res;
	res.real = num1.real + num2.real;
	res.img = num1.img + num2.img;
	return res;
}
