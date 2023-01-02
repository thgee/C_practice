// 연락처 관리 프로그램

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tel {
	char* name; // 이름
	char* tel_no; // 전화번호
	char* birth; // 생년월일
};
typedef struct tel TEL;

void sort(TEL** tel_list, int count);
void insert(TEL** tel_list, int* count, int max_num);
void print_all(TEL** tel_list, int count);
void delete_tel(TEL** tel_list, int* count);
void find_by_birth(TEL** tel_list, int count);
void RegFromFile(TEL** tel_list, int* count, int max_num);
void storeExit(TEL** tel_list, int count);

int main() {

	int max_num; // 최대 연락처 개수, 사용자로부터 입력받음
	printf("Max_num:");
	scanf("%d", &max_num);

	TEL** tel_list = (TEL**)malloc(sizeof(TEL*) * max_num); // max_num개 만큼 tel_list에 동적할당
	if (tel_list == NULL) { // 동적할당 성공 여부 체크
		printf("Not enough memory!");
		return -1;
	}

	int count = 0; // 현재 연락처 개수
	int menu;


	while (1) {

		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFile><6.Exit>\n");
		printf("Enter_the_menu_number:");
		scanf("%d", &menu);

		switch (menu) {
		case 1: insert(tel_list, &count, max_num); break;
		case 2: print_all(tel_list, count); break;
		case 3: delete_tel(tel_list, &count); break;
		case 4: find_by_birth(tel_list, count); break;
		case 5: RegFromFile(tel_list, &count, max_num); break;
		case 6: storeExit(tel_list, count); return 0;
		}
	}


}



void sort(TEL** tel_list, int count) {

	// 매번 자료가 등록될 때 마다 전체자료를 정렬하지 말고,
	// 일단 배열의 맨 뒤에 저장한 후
	// 삽입될 위치를 찾은 후 나머지 자료를 이동하는 방식으로 한다.

	TEL* temp = tel_list[count - 1]; // 방금 저장한 연락처를 temp에 임시로 저장
	for (int i = 0; i < count - 1; i++) { // 연락처를 하나씩 탐색

		if (strcmp(tel_list[i]->name, tel_list[count - 1]->name) < 0) { // 방금 저장한 연락처보다 사전상으로 빠르다면
			continue; // 건너뛰기
		}
		else if (strcmp(tel_list[i]->name, tel_list[count - 1]->name) > 0) { // 삽입되어야 할 위치를 찾으면

			// ------------- 연락처를 저장할 공간 생성 ------------------

			for (int j = count - 2; j >= i; j--) { // [i]부터 [count - 1]까지 뒤로 한칸씩 밀기
				tel_list[j + 1] = tel_list[j];
			}
			tel_list[i] = temp; // 연락처 삽입
			break;
		}
	}
}

void insert(TEL** tel_list, int* count, int max_num) {

	// ----------- 예외처리 --------------
	if (*count == max_num) { // 연락처 갯수가 max_num 개를 초과하면
		printf("OVERFLOW\n"); // 경고메세지 출력
		return; // 메뉴로 돌아감
	}

	(*count)++; // 연락처 개수 증가

	// --------------- 배열의 제일 끝에 연락처 등록 ---------------

	// ----------- tel_list 안에 연락처 동적할당 ------------

	tel_list[*count - 1] = (TEL*)malloc(sizeof(TEL));
	if (tel_list[*count - 1] == NULL) { // 동적할당 성공 여부 체크
		printf("Not enough memory!");
		return;
	}



	char buffer[101]; // 문자열을 임시로 입력받을 버퍼, 크기는 널문자를 제외 100바이트

	// -------- name 동적할당 및 저장 --------- 
	printf("Name:"); // 이름 입력
	scanf("%s", buffer);
	tel_list[*count - 1]->name = (char*)malloc(sizeof(char) * (strlen(buffer) + 1)); // buffer에 입력된 문자열의 길이 + 1 만큼 동적할당
	if (tel_list[*count - 1]->name == NULL) { // 동적할당 성공 여부 체크
		printf("Not enough memory!");
		return;
	}
	strcpy(tel_list[*count - 1]->name, buffer); // 이름 저장

	// -------------- tel_no 동적할당 및 저장 ------------

	printf("Phone_number:");
	scanf("%s", buffer); // 번호를 버퍼에 입력받음
	tel_list[*count - 1]->tel_no = (char*)malloc(sizeof(char) * (strlen(buffer) + 1)); // buffer에 입력된 문자열의 길이 + 1 만큼 동적할당
	if (tel_list[*count - 1]->tel_no == NULL) { // 동적할당 성공 여부 체크
		printf("Not enough memory!");
		return;
	}
	strcpy(tel_list[*count - 1]->tel_no, buffer); // 번호 저장


	// -------------- birth 동적할당 및 저장 ------------

	printf("Birth:");
	scanf("%s", buffer); // 생년월일을 버퍼에 입력받음
	tel_list[*count - 1]->birth = (char*)malloc(sizeof(char) * (strlen(buffer) + 1)); // buffer에 입력된 문자열의 길이 + 1 만큼 동적할당
	if (tel_list[*count - 1]->birth == NULL) { // 동적할당 성공 여부 체크
		printf("Not enough memory!");
		return;
	}
	strcpy(tel_list[*count - 1]->birth, buffer); // 생년월일 저장

	sort(tel_list, *count); // 정렬

	printf("<<%d>> \n", *count); // 연락처 갯수 출력
	return;
}

void print_all(TEL** tel_list, int count) {
	if (count == 0) return; // 등록된 사람이 없으면 출력하지 않음
	for (int i = 0; i < count; i++) // 연락처 출력
		printf("%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth);
}

void delete_tel(TEL** tel_list, int* count) {

	if (*count == 0) { // 저장된 연락처가 없으면 종료
		printf("NO MEMBER\n");
		return;
	}

	char buffer[101]; // 이름을 입력받아 임시로 저장
	printf("Name:");
	scanf("%s", buffer);

	for (int i = 0; i < *count; i++) {
		if (strcmp(buffer, tel_list[i]->name) == 0) { // 연락처에서 같은 이름을 찾으면
			// [i + 1]부터 [*count - 1]까지 앞으로 한칸씩 당김
			for (int j = i + 1; j < *count; j++) {
				*tel_list[j - 1] = *tel_list[j];
			}
			(*count)--; // 연락처 갯수 감소
			return;
		}
	}
	// 연락처에 없는 이름이면 메세지 출력 후 메뉴로 복귀
	printf("NO MEMBER\n");
	return;
}

void find_by_birth(TEL** tel_list, int count) {
	char tmp_month[3] = { '\0' };
	printf("Birth:");
	scanf("%s", &tmp_month); // 생일 달 입력

	// 등록된 연락처가 없는 경우에는 바로 종료
	if (count == 0) return;

	for (int i = 0; i < count; i++) {

		if (tmp_month[1] == '\0') { // 달이 한자리수라면
			if (strncmp(&tel_list[i]->birth[5], tmp_month, 1) == 0) { // 생일이 같으면
				printf("%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth); // 연락처 출력
				continue;
			}
		}
		else { // 달이 두자리수라면
			if (strncmp(&tel_list[i]->birth[4], tmp_month, 2) == 0) { // 생일이 같으면
				printf("%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth); // 연락처 출력
				continue;
			}
		}
	}
}

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

void storeExit(TEL** tel_list, int count) {

	FILE* fp = fopen("PHONE_BOOK.txt", "w"); // txt파일을 읽어옴
	for (int i = 0; i < count; i++) {
		fprintf(fp, "%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth); // 파일에 tel_list 저장
	}

	fclose(fp);


	// ----------- 메모리 해제 ------------

	for (int i = 0; i < count; i++) {// 각 TEL마다 멤버변수 메모리 해제
		if (tel_list[i]->name != NULL)
			free(tel_list[i]->name);
		if (tel_list[i]->tel_no != NULL)
			free(tel_list[i]->tel_no);
		if (tel_list[i]->birth != NULL)
			free(tel_list[i]->birth);
	}

	for (int i = 0; i < count; i++) // 현재 연락처 개수만큼 tel_list 내부의 TEL* 메모리 해제
		if (tel_list[i] != NULL)
			free(tel_list[i]);

	if (tel_list != NULL) // 2중포인터 tel_list 메모리 해제
		free(tel_list);

}
