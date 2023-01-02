// 11 - 10

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct date {
	int year, month, day;
};

struct date* select_min(struct date *date1, struct date *date2);

int main() {
	struct date day1, day2;
	scanf("%d/%d/%d", &day1.year, &day1.month, &day1.day);
	scanf("%d/%d/%d", &day2.year, &day2.month, &day2.day);
	struct date* p = select_min(&day1, &day2);
	printf("%d/%d/%d", p->year, p->month, p->day);

	return 0;
}

struct date* select_min(struct date* date1, struct date* date2) {
	struct date* p;
	if (date1->year < date2->year) p = date1;
	else if (date1->year > date2->year) p = date2;
	else {
		if (date1->month < date2->month) p = date1;
		else if (date1->month > date2->month) p = date2;
		else{
			if (date1->day < date2->day)p = date1;
			else if (date1->day > date2->day)p = date2;
			else p = date1;
		}
	}
	return p;
}
