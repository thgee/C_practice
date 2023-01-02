// 연락처 관리 프로그램

#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUM 100

#include <stdio.h>
#include <string.h>

struct tel {
	char name[21]; // 이름
	char tel_no[16]; // 전화번호
	char birth[9]; // 생년월일
}person;

void insert(struct tel tel_list[], int* count);
void print_all(struct tel tel_list[], int count);
void delete_tel(struct tel tel_list[], int* count);
void find_by_birth(struct tel tel_list[], int count);

int main() {

	struct tel tel_list[MAX_NUM]; // 최대 100개 가능
	int count = 0;
	int menu;


	while (1) {

		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
		printf("Enter_the_menu_number:");
		scanf("%d", &menu);

		switch (menu) {
		case 1: insert(tel_list, &count); break;
		case 2: print_all(tel_list, count); break;
		case 3: delete_tel(tel_list, &count); break;
		case 4: find_by_birth(tel_list, count); break;
		case 5: return 0; // 종료
		}
	}

	return 0;
}


void insert(struct tel tel_list[], int* count) {

	// ----------- 예외처리 --------------
	if (*count == 100) { // 연락처 갯수가 100개를 넘어가면
		printf("OVERFLOW\n"); // 경고메세지 출력
		return; // 메뉴로 돌아감
	}

	char tmp_name[21]; // 입력받은 name을 임시로 저장

	printf("Name:"); // 이름 입력
	scanf("%s", tmp_name);


	// 매번 자료가 등록될 때 마다 전체자료를 정렬하지 말고,
	// 삽입될 위치를 찾은 후 나머지 자료를 이동하는 방식으로 한다.

	for (int i = 0; i < *count; i++) {
		if (strcmp(tel_list[i].name, tmp_name) < 0) { // 현재 입력받은 이름이 배열에 저장된 이름보다  
			// 사전상으로 뒤쪽에 있어야 한다면
			continue; // 건너뛰기
		}
		else { // 입력받은 이름이 있어야 할 위치를 찾으면

			// ------------- 연락처 등록 ------------------
			for (int j = *count - 1; j >= i; j--) { // [i]부터 [count - 2]까지 뒤로 한칸씩 밀기
				tel_list[j + 1] = tel_list[j];
			}
			strcpy(tel_list[i].name, tmp_name); // 이름 저장
			printf("Phone_number:"); scanf("%s", tel_list[i].tel_no); // 번호 저장
			printf("Birth:");	scanf("%s", tel_list[i].birth); // 생년월일 저장
			(*count)++;
			printf("<<%d>> \n", *count); // 연락처 갯수 출력
			return;
		}


	}
	// 저장할 자리를 찾지 못했다면 제일 뒤에 저장 
	strcpy(tel_list[*count].name, tmp_name); // 이름 저장
	printf("Phone_number:"); scanf("%s", tel_list[*count].tel_no); // 번호 저장
	printf("Birth:");	scanf("%s", tel_list[*count].birth); // 생년월일 저장
	(*count)++; // 연락처 갯수 증가
	printf("<<%d>> \n", *count); // 연락처 갯수 출력
	return;

}

void print_all(struct tel tel_list[], int count) {
	if (count == 0) return; // 등록된 사람이 없으면 출력하지 않음
	for (int i = 0; i < count; i++) // 연락처 출력
		printf("%s %s %s\n", tel_list[i].name, tel_list[i].tel_no, tel_list[i].birth);
}

void delete_tel(struct tel tel_list[], int* count) {

	if (*count == 0) { // 저장된 연락처가 없으면 종료
		printf("NO MEMBER\n");
		return;
	}

	char tmp_name[21]; // 이름을 입력받아 임시로 저장
	printf("Name:");
	scanf("%s", tmp_name);

	for (int i = 0; i < *count; i++) {
		if (strcmp(tmp_name, tel_list[i].name) == 0) { // 연락처에서 같은 이름을 찾으면
			// [i + 1]부터 [*count - 1]까지 앞으로 한칸씩 당김
			for (int j = i + 1; j < *count; j++) {
				tel_list[j - 1] = tel_list[j];
			}
			(*count)--; // 연락처 갯수 감소
			return;
		}
	}
	// 연락처에 없는 이름이면 메세지 출력 후 메뉴로 복귀
	printf("NO MEMBER\n");
	return;
}

void find_by_birth(struct tel tel_list[], int count) {
	char tmp_month[3] = { '\0' };
	printf("Birth:");
	scanf("%s", &tmp_month); // 생일 달 입력
	
	// 등록된 연락처가 없는 경우에는 바로 종료
	if (count == 0) return;

	for (int i = 0; i < count; i++) {

		if (tmp_month[1] == '\0') { // 달이 한자리수라면
			if (strncmp(&tel_list[i].birth[5], tmp_month, 1) == 0) { // 생일이 같으면
				printf("%s %s %s\n", tel_list[i].name, tel_list[i].tel_no, tel_list[i].birth); // 연락처 출력
				continue;
			}
		}
		else { // 달이 두자리수라면
			if (strncmp(&tel_list[i].birth[4], tmp_month, 2) == 0) { // 생일이 같으면
				printf("%s %s %s\n", tel_list[i].name, tel_list[i].tel_no, tel_list[i].birth); // 연락처 출력
				continue;
			}
		}
	}
}
