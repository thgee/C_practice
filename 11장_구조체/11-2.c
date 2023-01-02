// 11 - 2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Time {
	int hour, min, sec;
};

int main() {
	
	struct Time t1, t2;
	int hour, min, sec;

	scanf("%d%d%d", &t1.hour, &t1.min, &t1.sec);
	scanf("%d%d%d", &t2.hour, &t2.min, &t2.sec);

	hour = t2.hour - t1.hour;
	min = t2.min - t1.min;
	sec = t2.sec - t1.sec;

	if (sec < 0) {
		min -= 1;
		sec += 60;
	}
	
	if (min < 0) {
		hour -= 1;
		min += 60;
	}

		printf("%d %d %d", hour, min, sec);

	return 0;
}