#define _CRT_SECURE_NO_WARNINGS
#include "my_func.h"

void RegFromFile(TEL** tel_list, int* count, int max_num) {

	FILE* fp = fopen("PHONE_BOOK.txt", "r"); // txt파일을 읽어옴
	char buffer[101]; // 임시로 문자열을 저장할 버퍼

	while (1) {

		// ----------- 예외처리 --------------
		if (*count == max_num) { // 연락처 갯수가 max_num 개를 초과하면
			printf("OVERFLOW\n"); // 경고메세지 출력
			return; // 메뉴로 돌아감
		}


		fgets(buffer, 101, fp); // 파일을 한 줄 읽어옴
		if (feof(fp)) return; // 파일의 끝에 도달하면 중단

		(*count)++; // 연락처 개수 증가



		// tel_list의 원소 동적할당
		tel_list[*count - 1] = (TEL*)malloc(sizeof(TEL));
		if (tel_list[*count - 1] == NULL) { // 동적할당 성공 여부 체크
			printf("Not enough memory!");
			return -1;
		}

		// --------------- 배열의 제일 끝에 연락처 등록 ---------------
		// ----------- 공백을 기준으로 잘라서 이름, 번호, 생년월일 동적할당 및 저장 ------------

		int flag = 1; // 이름, 번호, 생년월일을 구분할 플래그
		// 이름 : 1	번호 : 2	 생년월일 : 3
		for (int i = 0, start = 0, len = 0; i < strlen(buffer); i++) { // i가 buffer의 개행문자까지 순환

			// -------- name 동적할당 및 저장 --------- 
			if (buffer[i] == ' ' && flag == 1) { // 첫 번째 공백을 만나면
				tel_list[*count - 1]->name = (char*)malloc(sizeof(char) * (len + 1)); // 단어의 길이 + 1 만큼 동적할당
				if (tel_list[*count - 1]->name == NULL) { // 동적할당 성공 여부 체크
					printf("Not enough memory!");
					return;
				}
				strncpy(tel_list[*count - 1]->name, &buffer[start], len); // 이름 저장
				tel_list[*count - 1]->name[start + len] = '\0'; // name의 끝에 널문자 저장

				start = i + 1; // start 인덱스를 다음 단어의 첫번째 문자에 가져다 둠
				len = 0; // 단어의 길이 리셋
				flag = 2; // 플래그 변경
			}

			// -------- tel_no 동적할당 및 저장 --------- 
			else if (buffer[i] == ' ' && flag == 2) { // 두 번째 공백을 만나면
				tel_list[*count - 1]->tel_no = (char*)malloc(sizeof(char) * (len + 1)); // 단어의 길이 + 1 만큼 동적할당
				if (tel_list[*count - 1]->tel_no == NULL) { // 동적할당 성공 여부 체크
					printf("Not enough memory!");
					return;
				}
				strncpy(tel_list[*count - 1]->tel_no, &buffer[start], len); // 전화번호 저장
				tel_list[*count - 1]->tel_no[len] = '\0'; // 전화번호의 끝에 널문자 저장

				start = i + 1; // start 인덱스를 다음 단어의 첫번째 문자에 가져다 둠
				len = 0; // 단어의 길이 리셋
				flag = 3; // 플래그 변경
			}


			// -------- birth 동적할당 및 저장 --------- 
			else if (buffer[i] == '\n' && flag == 3) { // 개행문자를 만나면
				tel_list[*count - 1]->birth = (char*)malloc(sizeof(char) * (len + 1)); // 단어의 길이 + 1 만큼 동적할당
				if (tel_list[*count - 1]->birth == NULL) { // 동적할당 성공 여부 체크
					printf("Not enough memory!");
					return;
				}
				strncpy(tel_list[*count - 1]->birth, &buffer[start], len); // 생년월일 저장
				tel_list[*count - 1]->birth[len] = '\0'; // 생년월일의 끝에 널문자 저장

			}

			else len++; // 공백을 만나기 전까지 단어의 길이 카운트
		}

		sort(tel_list, *count); // 정렬

	}
	fclose(fp);
}
