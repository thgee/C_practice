
#define _CRT_SECURE_NO_WARNINGS
#include "my_func.h"

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
