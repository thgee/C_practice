#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct Student {
	char name[11];
	int scr;
}Student;

int main() {

	FILE* fp = fopen("student.dat", "r");
	Student arr[3];
	for (int i = 0; i < 3; i++) {
		fscanf(fp, "%s%d", arr[i].name, &arr[i].scr);
		printf("%s %d\n", arr[i].name, arr[i].scr);
	}

	fclose(fp);

	return 0;
}
