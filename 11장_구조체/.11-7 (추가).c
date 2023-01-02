// .11-7 (추가)cpp

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct student* change(struct student* st);

typedef struct student {
	char name[22];
	char r_name[22];
} student;

int main() {

	int N;
	scanf("%d", &N);
	getchar();
	student st[10] = {'\0'};
	for (int i = 0; i < N; i++)
		gets(st[i].name);
	student* long_st = change(st);
	for (int i = 0; i < N; i++)
		printf("%s\n", st[i].r_name);
	printf("longest = %s", long_st->r_name);




	return 0;
}

struct student* change(struct student* st) {

	// N을 인자로 못 받아와서 함수 내에서 직접 N을 구해주어야 함

	int N = 0;
	int n = 0;
	while (1) {
		if (*(st[n].name) == '\0') break;
		N++;
		n++;
	}


	int max_len = 0; // 가장 긴 문자 길이
	student* max_st = NULL;
	for (student* p = st; p < st + N; p++) {
		int len = strlen(p->name);
		for (int i = 0; i < len; i++) {
			if (p->name[i] == ' ') { // 공백을 기준으로 앞, 뒤 단어를 change
				for (int j = i + 1, k = 0; j < len; j++, k++) {
					p->r_name[k] = p->name[j];
				}
				p->r_name[len - 1 - i] = ' ';

				for (int j = len - i, k = 0; j < len; j++, k++) {
					p->r_name[j] = p->name[k];
				}
			}
		}
		p->r_name[len] = '\0';
		if (len > max_len) {
			max_len = len;
			max_st = p;
		}
	}
	return max_st;
}



