// 11 - 11

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student {
	char name[20];
	int scr;
};

struct student * select_min(struct student* st);

int main() {

	struct student std[5];
	for (struct student* p = std; p < std + 5; p++) {
		scanf("%s%d", &p->name, &p->scr);
	}


	struct student* res = select_min(std);
	printf("%s %d", res->name, res->scr);

	return 0;
}

struct student* select_min(struct student* st) {
	int min = st->scr;
	struct student *min_st = st;
	for (struct student* p = st; p < st + 5; p++) {
		if (min_st->scr > p->scr) min_st = p;
	}

	return min_st;

}
