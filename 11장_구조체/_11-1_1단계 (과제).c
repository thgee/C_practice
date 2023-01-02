// _11-1_1단계(과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct student {
	char name[10]; // 이름
	char id[11]; // 학번
	char grade; // 성적

};

int main() {

	struct student st[5];
	struct student search;

	for (int i = 0; i < 5; i++) {
		scanf("%s%s", &st[i].name, &st[i].id); // 학생들의 이름, 학번 입력
		getchar(); // 개행문자를 없애줌
		scanf("%c", &st[i].grade); // 성적 입력
	}

	scanf("%s", &search.name); // search 구조체에 name 입력


	for (int i = 0; i < 5; i++) {
		if (strcmp(search.name, st[i].name) == 0) { // 이름을 기준으로 학생을 찾음
			search = st[i]; // 찾은 학생을 search 구조체에 저장
		}
	}

	printf(" %s %c", search.id, search.grade); // 아이디와 이름 출력

	return 0;
}

