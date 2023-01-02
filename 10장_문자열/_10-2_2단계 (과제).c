// 10-2_2단계 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	char input[500]; // 첫 문장을 입력받을 배열
	char words[50][500]; // 단어별로 분리하여 저장할 2차원 배열
	gets(input); // 공백 포함하여 입력
	char add_word[500]; // 추가할 단어
	gets(add_word); // 추가할 단어 입력

	int num_words = 0; // 2차원 배열에 저장된 단어의 갯수

	int input_len = strlen(input) + 1; // input 문자열의 길이를 저장할 함수
	for (int i = 0, word_len = 0; i < input_len; i++) {
		if (input[i] == ' ' || input[i] == '\0') { // 공백이나 널문자를 만나면
			input[i] = '\0'; // 공백 자리에 널문자를 넣어줌
			strcpy(words[num_words], &input[i] - word_len); // 2차원 배열 words에 방금 탐색한 단어를 저장함
			num_words++; // 단어 갯수 카운트
			word_len = 0; // 단어의 길이 리셋
			continue;
		}
		word_len++; // 단어의 길이 카운트
	}


	// --------- 단어 추가 -------------
	int rep = 0;
	for (int i = 0; i < num_words; i++) {
		if (strcmp(words[i], add_word) == 0) rep++; // 단어 하나하나 비교하며 중복 검사
	}
	if (rep == 0){// 중복이 하나도 없었다면 rep은 0일 것이다.
		strcpy(words[num_words], add_word); // 단어를 추가
		num_words++; // 단어 하나를 더 추가했으니 단어의 갯수도 증가
	}



// ---------- 각 단어 출력 -------------

	for (int i = 0; i < num_words; i++)
		printf("%s\n", words[i]); // words 안에 있는 단어들 모두 출력


// ----------- 정렬 ---------------

	// 선택정렬 사용
	char tmp_word[300]; // 스왑 시 단어를 저장할 임시 배열
	for (int i = 0; i < num_words - 1; i++) { // 단어의 갯수만큼 반복
		int fst = i;
		for (int j = i + 1; j < num_words; j++) {
			if(strcmp(words[fst], words[j]) == 1){ // 사전순으로 되어있지 않으면
				fst = j; // 더 빠른 단어의 인덱스를 fst에 저장
			}
		}
		strcpy(tmp_word, words[i]); // 스왑
		strcpy(words[i], words[fst]);
		strcpy(words[fst], tmp_word);
	}



// ----------- 한 문장으로 결합 -----------
	
	char res[10000]; // 단어들을 한 문장으로 합칠 배열
	res[0] = '\0'; // res배열의 끝을 알리기 위해 첫 번째 원소에 널문자를 넣어준다
		char* p = res; // 단어의 시작점을 가리킬 포인터
	for (int i = 0; i < num_words; i++) {
		strcat(res, words[i]); // res 배열의 뒤쪽에 words의 각 단어들을 이어붙임
		*(p + strlen(words[i])) = ' '; // 각 단어의 끝마다 공백을 넣어줌
		*(p + strlen(words[i]) + 1) = '\0'; // 공백의 다음칸에 널문자를 넣어줌
		p += strlen(words[i]) + 1; // 포인터 p가 단어의 시작 주소를 가리키게 함
	}
	printf("%s", res); // 정렬된 문자열 출력

	return 0;
}