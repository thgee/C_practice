// 2차인증 예상문제 2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[10];
	char id[11];
	char grade;
}student;

int main() {

	student st[5];
	for (int i = 0; i < 5; i++) {
		scanf("%s %s %c", st[i].name, st[i].id, &st[i].grade);
	}
	char search[10];
	scanf("%s", search);

	for (int i = 0; i < 5; i++) 
		if (strcmp(st[i].name, search) == 0)
			printf(" %s %c",st[i].id, st[i].grade);


	return 0;
}