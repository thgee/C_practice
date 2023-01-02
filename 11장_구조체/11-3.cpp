// 11 - 3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Student {
	char name[10];
	int scr;
};

int main() {

	int sum = 0;
	float avg;
	struct Student person[5];

	for (int i = 0; i < 5; i++) {
		scanf("%s%d", &person[i].name, &person[i].scr);
		sum += person[i].scr;
	}

	avg = sum / 5.0f;

	for (int i = 0; i < 5; i++) {
		if (person[i].scr < avg) printf("%s ", person[i].name);
	}



	return 0;
}