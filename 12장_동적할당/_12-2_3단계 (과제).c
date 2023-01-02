//_12-2_3단계 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main() {

	char A[101], B[101];
	gets(A); // 문자열 A, B 입력
	gets(B);

	// ------------ 단어의 갯수 저장 -------------

	int num1 = 0, num2 = 0; // num1 : A의 단어 갯수		num2 : B의 단어 갯수
	for (int i = 0; i <= strlen(A); i++) {
		if (A[i] == ' ' || A[i] == '\0') { // 공백이나 널문자를 만나면
			num1++; // 단어 갯수 카운트
		}
	}
	for (int i = 0; i <= strlen(B); i++) {
		if (B[i] == ' ' || B[i] == '\0') { // 공백이나 널문자를 만나면
			num2++; // 단어 갯수 카운트
		}
	}


	// ------------- 2차원 배열 동적할당 --------------

	char** str1 = (char**)malloc(sizeof(char*) * num1); // A 문자열의 단어 갯수 만큼 포인터 배열 동적할당
	if (str1 == NULL) { // 동적할당 성공 여부 체크
		printf("Not enough momory!");
		return -1;
	}

	char** str2 = (char**)malloc(sizeof(char*) * num2); // B 문자열의 단어 갯수 만큼 포인터 배열 동적할당
	if (str2 == NULL) { // 동적할당 성공 여부 체크
		printf("Not enough momory!");
		return -1;
	}


	// ---------- 2차원 배열 안에 1차원 문자열 동적할당 ------------


	int length = 0; // 단어의 길이
	for (int i = 0, j = 0; i <= strlen(A); i++) {
		if (A[i] != ' ' && A[i] != '\0') { // A를 돌면서 공백이나 널문자가 아니라면
			length++; // 단어의 길이 증가
		}
		else { // 공백이나 널문자를 만나면
			str1[j] = (char*)malloc((length + 1) * sizeof(char)); // 단어의 길이 + 1 만큼의 크기를 동적할당
			if (str1[j] == NULL) { // 동적할당 성공 여부 체크
				printf("Not enough momory!");
				return -1;
			}
			j++; // 포인터 베열의 인덱스 증가
			length = 0; // 단어의 길이 초기화
		}
	}


	for (int i = 0, j = 0; i <= strlen(B); i++) {
		if (B[i] != ' ' && B[i] != '\0') { // B를 돌면서 공백이나 널문자가 아니라면
			length++; // 단어의 길이 증가
		}
		else { // 공백이나 널문자를 만나면
			str2[j] = (char*)malloc((length + 1) * sizeof(char)); // 단어의 길이 + 1 만큼의 크기를 동적할당
			if (str2[j] == NULL) { // 동적할당 성공 여부 체크
				printf("Not enough momory!");
				return -1;
			}
			j++; // 포인터 베열의 인덱스 증가
			length = 0; // 단어의 길이 초기화
		}
	}




	// ------------- 2차원배열에 단어 저장 ---------------

	for (int i = 0, j = 0, k = 0; i <= strlen(A); i++) { // i가 A문자열의 널문자까지 탐색

		if (A[i] != ' ' && A[i] != '\0') { // 공백이나 널문자가 아니라면
			str1[k][j] = A[i]; // str1에 저장
			j++;
		}
		else { // 공백이나 널문자를 만나면
			str1[k][j] = '\0'; // 단어의 끝에 널문자를 붙여주고
			k++; // 다음 단어로 넘어감
			j = 0;
		}
	}

	for (int i = 0, j = 0, k = 0; i <= strlen(B); i++) { // i가 B문자열의 널문자까지 탐색
		if (B[i] != ' ' && B[i] != '\0') { // 공백이나 널문자가 아니라면
			str2[k][j] = B[i]; // str1에 저장
			j++;
		}
		else { // 공백이나 널문자를 만나면
			str2[k][j] = '\0'; // 단어의 끝에 널문자를 붙여주고
			k++; // 다음 단어로 넘어감
			j = 0;
		}
	}



	// ----------- str2 내림차순 정렬 ----------

	for (int i = 0; i < num2; i++) {
		for (int j = 0; j < num2 - i - 1; j++) {
			char* temp; // swap을 위한 임시 버퍼
			if (strlen(str2[j]) < strlen(str2[j + 1])) { // 길이가 큰 순서대로 버블정렬
				temp = str2[j];
				str2[j] = str2[j + 1];
				str2[j + 1] = temp;
			}
			if (strlen(str2[j]) == strlen(str2[j + 1])) // 길이가 같다면
				if (strcmp(str2[j], str2[j + 1]) > 0) { // 사전순으로 정렬
					temp = str2[j];
					str2[j] = str2[j + 1];
					str2[j + 1] = temp;
				}
		}
	}


	// -------------- 합성어 출력-------------------

	for (int i = 0; i < num2; i++) { // str2의 단어 하나씩 잡고
		int flag = 0; // 해당 합성어를 출력했는지 알려주는 플래그
		for (int j = 0; j < num1; j++) { // str1을 탐색한다.
			if (strncmp(str2[i], str1[j], strlen(str1[j])) == 0) { // str1의 단어가 str2에 포함되어 있다면
				for (int k = 0; k < num1; k++) { // str1을 한바퀴 더 돈다.
					if (j == k) // 같은 단어로 이루어진 합성어는 취급하지 않는다.
						continue;
					if (strcmp(str2[i] + strlen(str1[j]), str1[k]) == 0) { // str1의 단어 두개가 str2에 포함된다면
						printf("%s\n", str2[i]); // 해당 합성어 출력
						flag = 1; // 합성어를 출력했으면 flag에 1 저장
					}
				}
			}
			if (flag == 1)  // 합성어를 출력했다면
				break; // 다음 단어로 넘어감
		}
	}



	// --------------- 메모리 해제 --------------------

	for (int i = 0; i < num1; i++) {
		if (str1[i] != NULL)
			free(str1[i]);
	}

	for (int i = 0; i < num2; i++) {
		if (str2[i] != NULL)
			free(str2[i]);
	}

	if (str1 != NULL)
		free(str1);

	if (str2 != NULL)
		free(str2);


	return 0;
}


