#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct Student {
	char name[11];
	int scr;
}Student;

int main() {
	
	FILE* fp = fopen("student.dat", "w");
	Student arr[3];
	for (int i = 0; i < 3; i++) {
			scanf("%s%d", arr[i].name, &arr[i].scr);
			fprintf(fp, "%s %d ", arr[i].name, arr[i].scr);
	}

	fclose(fp);

	return 0;
}
