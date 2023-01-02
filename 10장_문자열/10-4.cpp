// 10-4

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main() {

	char a[101], b[101];
	
	// a 길이 출력
	int len = 0;
	while (1) {
		scanf("%c", &a[len]);
		if (a[len] == '\n') break;
		len++;
	}

	scanf("%s", b);

	printf("%d ", len);
	
	int cnt = 0;
	for(int i = 0; i < len; i++){
		if (a[i] == b[i]) cnt++;
		}

	(cnt == len) ? printf("%d", 1) : printf("%d", 0);
	return 0;
}
