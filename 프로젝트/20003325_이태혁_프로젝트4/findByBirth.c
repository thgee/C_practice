#define _CRT_SECURE_NO_WARNINGS
#include "my_func.h"

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
