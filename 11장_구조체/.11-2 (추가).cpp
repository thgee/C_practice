// .11-2 (Ãß°¡)cpp

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


struct student {
	int id;
	int scr[3];
	float avg;
}; typedef struct student st;


void average(st* a);

int main() {
	st a[10];
	int N;
	scanf("%d", &N);
	// input
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i].id);
		for (int j = 0; j < 3; j++)
			scanf("%d", &a[i].scr[j]);
	}



	// sort
	st temp;
	for (int i = 0; i < N - 1; i++)
		for (int j = i; j < N; j++)
			if (a[i].id > a[j].id) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}

	// adjust
	for (int i = 0; i < N; i++)
		average(&a[i]);


	// output
	for (int i = 0; i < N; i++)
		printf("%04d %.1f\n", a[i].id, a[i].avg);

	return 0;

}


void average(st* a) {
	int sum = 0;
	for (int i = 0; i < 3; i++)
		sum += a->scr[i];
	a->avg = sum / 3.0f;

}
