// 12-4

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	char name[10];
	int kor, eng, math;
	float avg;
} student;


int main() {

	int N;
	scanf("%d", &N);
	
	student* st = (student*) malloc (sizeof(student) * N);
	if (st == NULL) {
		printf("Not enough Memory!");
		return -1;
	}	
	for (int i = 0; i < N; i++) {
		scanf("%s%d%d%d", st[i].name, &st[i].kor, &st[i].eng, &st[i].math);
	}
	
	for (int i = 0; i < N; i++) {
		st[i].avg = (st[i].kor + st[i].eng + st[i].math) / 3.0f;
	}

	for (int i = 0; i < N; i++) {
		printf("%s %.1f", st[i].name, st[i].avg);
		if (st[i].kor >= 90 || st[i].eng >= 90 || st[i].math >= 90) printf("GREAT ");
		if (st[i].kor < 70 || st[i].eng < 70 || st[i].math < 70) printf("BAD ");
		printf("\n");
	}

	if(st != NULL)
		free(st);		 

	return 0;
}