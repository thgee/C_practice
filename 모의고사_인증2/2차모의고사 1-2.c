// 2차모의고사 1 - 2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	int N, M1, M2;
	char str[20][101];

	scanf("%d%d%d", &N, &M1, &M2);
	getchar();
	
	// ---------- 문자열 입력 --------------
	for (int i = 0; i < N; i++) {
		gets(str[i]);
	}

	// ----------- 문자열의 길이를 기준으로 내림차순 정렬 ----------
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			char tmp[101];
			if (strlen(str[j + 1]) > strlen(str[j])) { // 버블정렬
				strcpy(tmp, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], tmp);
			}
		}
	}

	// ---------- 가장 짧은 길이의 인덱스 저장 ----------
	int shortest_idx;
	for (int i = 0; i < N; i++) {
		if (strlen(str[N - 1]) == strlen(str[i])) {
			shortest_idx = i;
			break;
		}
	}

	// ------------- 가장 긴 문자열의 M1, 가장 짧은 문자열의 M2번째 단어를 각각 temp1, temp2에 저장 ----------
	char temp1[101], temp2[101];
	for (int j = 0, idx = 0; j <= strlen(str[0]); j++) { // j가 첫번째 문자열의 널문자까지 탐색
		if (idx == M1) { // M1번째에 단어의 첫문자에 j가 도달하면

			// ----------- M1번째 단어의 길이 저장 ------------
			for (int k = j;; k++) { // k가 j부터 탐색하면서
				if (str[0][k] == ' ' || str[0][k] == '\0') { // k가 단어의 끝 + 1까지 도달하면

					int len = k - j; // 단어의 길이 저장
					strncpy(temp1, &str[0][j], len); // temp1에 M1번째 단어 저장
					temp1[len] = '\0';
					j = k;
					break;
				}
			}
		}
		if (str[0][j] == ' ' || str[0][j] == '\0') // 공백이나 널문자 만나면
			idx++;
	}

	for (int j = 0, idx = 0; j <= strlen(str[shortest_idx]); j++) { // j가 첫번째 문자열의 널문자까지 탐색
		if (idx == M2) { // M2번째에 단어의 첫문자에 j가 도달하면

			// ----------- M2번째 단어의 길이 저장 ------------
			for (int k = j;; k++) { // k가 j부터 탐색하면서
				if (str[shortest_idx][k] == ' ' || str[shortest_idx][k] == '\0') { // k가 단어의 끝 + 1까지 도달하면
					int len = k - j; // 단어의 길이 저장
					strncpy(temp2, &str[shortest_idx][j], len); // temp2에 M2번째 단어 저장
					temp2[len] = '\0';
					j = k;
					break;
				}
			}
		}
		if (str[shortest_idx][j] == ' ' || str[shortest_idx][j] == '\0') // 공백이나 널문자 만나면
			idx++;
	}

	// ------------- temp1과 temp2중 사전상 빠른 순서대로 res에 저장 -----------
	char res[201];
	if (strcmp(temp1, temp2) < 0) {
		strcpy(res, temp1);
		strcat(res, temp2);
	}
	else {
		strcpy(res, temp2);
		strcat(res, temp1);
	}

	// ------------- 출력 ------------
	printf("%s\n%s\n", str[0], str[shortest_idx]);
	printf("%s", res); // 한번의 출력문으로 출력

	return 0;
}

/*
5 4 2
book desk pencil paper
orange apple banana lemon grape
red yellow green orange blue white black
candy cake icecream
july august september october november december
*/