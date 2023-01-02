#define _CRT_SECURE_NO_WARNINGS
#include "my_func.h"


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