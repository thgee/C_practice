#define _CRT_SECURE_NO_WARNINGS
#include "my_func.h"

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
