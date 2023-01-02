#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct string {
	char* str; // 문자열을 가리키는 포인터, 문자 배열 (char str[])로 선언한 경우 50% 감점
	int words; // str이 가리키는 문자열에 포함된 단어 수
};



int main() {

	int N;
	scanf("%d", &N);
	char buffer[101];

	struct string* arr = (struct string*)malloc(sizeof(struct string) * N);
	if (arr == NULL) {
		printf("not enough memory");
		return -1;
	}
	getchar();
	for (int i = 0; i < N; i++) {
		gets(buffer);
		arr[i].str = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
		if (arr[i].str == NULL) {
			printf("not enough memory");
			return -1;
		}
		strcpy(arr[i].str, buffer);
		arr[i].words = 0;
	}

	// -------- 단어개수 저장--------
	for (int i = 0; i < N; i++) { // 한줄 잡고
		for (int j = 0; j <= strlen(arr[i].str); j++) { // j가 각 줄의 널문자까지 탐색
			
			if (arr[i].str[j] == ' ' || arr[i].str[j] == '\0') // 공백 or 널문자면
				arr[i].words++; 
	}
}

	// ---------- sort ----------
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N - i - 1; j++) {
			struct string tmp;
			if (arr[j].words < arr[j + 1].words) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}

	// ------- 출력 ---------
	for (int i = 0; i < N; i++)
		printf("%s %d\n", arr[i].str, arr[i].words);

	// -------- 해제 ---------
	for (int i = 0; i < N; i++) 
		if (arr[i].str != NULL) 
			free(arr[i].str);

	if (arr != NULL)
		free(arr);

	return 0;
}

	/*
	
5
why so serious
icecream makes everything better
you make me smile
c language midterm and final
see you
	*/