// 모의고사 3-1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void StringAdd(char arr[], char ch, int index);
int Convertor(char x);

int main() {

	char str[100];
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i + 1] == '\0') break;

		if (Convertor(str[i]) % 2 == 1 && Convertor(str[i + 1]) % 2 == 1) {
			StringAdd(str, '+', i + 1); // 홀수 사이에 + 추가
			i++;
		}
		else if (Convertor(str[i]) % 2 == 0 && Convertor(str[i + 1]) % 2 == 0) {
			StringAdd(str, '*', i + 1); // 짝수 사이에 * 추가
			i++;
		}
	}
	printf("%s", str);

	return 0;
}



void StringAdd(char arr[], char ch, int index){
	// 해당 배열의 해당 인덱스가 나타내는 위치에 ‘+’ 혹은 ‘*' 를 삽입한다
	for (int i = strlen(arr); i >= index; i--) { // 널문자까지 탐색
		arr[i + 1] = arr[i];
	}
	arr[index] = ch;
}


int Convertor(char x){
	// 숫자 문자를 숫자로 변환한다.
	return (int)x - '0';
}