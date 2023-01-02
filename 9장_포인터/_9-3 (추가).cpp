//_9-3 (Ãß°¡)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void eliminate(char arr[]);

int main() {

	char str[100];

	// input
	char* p_str = str;
	while (1) {
		scanf("%c", p_str);
		if (*p_str == '*') break;
		p_str++;
	}

	eliminate(str);

	// print
	p_str = str;
	while (1) {
		printf("%c", *p_str);
		if (*p_str == '*') break;
		p_str++;
	}

	return 0;
}


void eliminate(char arr[]) {

	char* p_str = arr;
	int len = 0;

	while(1){
		len++;
		if (*p_str == '*') break;
		p_str++;
	}

	char* p_idx = arr + 1;
	for (p_str = arr + 1; p_str < arr + len; p_str++) {
		int cnt = 0;
		for (char* q_str = arr; q_str < p_str; q_str++) {
			if (*p_str == *q_str) cnt++;
		}
		if (cnt == 0) {
			*p_idx = *p_str;
			p_idx++;
		}
	}
}
