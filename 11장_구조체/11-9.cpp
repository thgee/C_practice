// 11 - 9

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


struct result {
	int max;
	int min;
	char pass;
	int passdiff;
	int diff;
};

void passorfail(struct result* res);



int main() {
	struct result st;
	scanf("%d%d%d", &st.max, &st.min, &st.passdiff);
	passorfail(&st);
	printf("%d %c", st.diff, st.pass);
	return 0;
}

void passorfail(struct result* res) {
	res->diff = res->max - res->min;
	if (res->passdiff > res->diff) res->pass = 'P';
	else res->pass = 'F';
}
