// _11-1_2단계(과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

	int cnt = 0; // 조건에 맞는 학생이 하나도 없을 경우를 처리할 변수
	for (int i = 0; i < 5; i++) {
		if (search.grade == st[i].grade && strncmp(st[i].id, search.id, 4) == 0) { // 성적이 같으면서 입학년도가 같으면
			if (strcmp(search.name, st[i].name) == 0) continue; // 자기 자신은 출력하지 않음
			printf("%s ", st[i].name); // 이름을 출력
		}
		else cnt++; // 조건에 맞는 학생이 아닐 시 cnt 증가
	}
	
	if (cnt == 4) printf("%d", 0); // 조건에 맞는 학생이 하나도 없으면 0 출력

	printf("\n"); // 개행

	char str_year[5]; // 입학년도
	int year;
	strncpy(str_year, search.id, 4); // 학번에서 앞 4자리만 가져와 year에 저장함
	year = atoi(str_year); // 입학년도를 정수형으로 변환함
	printf("%d %d", year, year % 131); // 입학년도와 131로 나눈 나머지를 출력
	

	return 0;
}

