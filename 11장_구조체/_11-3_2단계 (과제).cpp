// 11 - 3 _ 2단계 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct hotel_info {
	char name[31];
	int G; // 등급 1~5
	double score; // 평판도 1~5
	double D; // 거리
	char bf; // 조식포함여부 Y or N
};

int in_hotel_info(struct hotel_info* p);
void out_hotel_info(struct hotel_info* p, int N, int G, double D);



int main() {


	struct hotel_info hotels[100]; // 호텔 구조체 배열
	int N = in_hotel_info(hotels); // 호텔정보를 입력받고 호텔의 수를 저장함

	int G; // 호텔의 등급
	double D; // 거리조건 입력
	scanf("%d%lf", &G, &D);

	
	out_hotel_info(hotels, N, G, D); // 조건에 맞는 호텔 출력
	
	return 0;
}


int in_hotel_info(struct hotel_info* p) {
	int N = 0; // 입력받은 호텔의 수
	for (struct hotel_info* i = p;; i++) {
		scanf("%s", i->name); // 호텔의 이름 입력받음
		if (*(i->name) == '0') break; // 호텔의 이름으로 0을 입력받으면 종료
		scanf("%d%lf%lf", &i->G, &i->score, &i->D); // 호텔의 정보를 입력받음
		getchar(); // 공백 제거
		scanf("%c", &i->bf); // 호텔의 조식제공여부 입력
		N++; // 입력받은 호텔 수 증가
	}
	return N; // 정보가 입력된 호텔의 수 반환
}


void out_hotel_info(struct hotel_info* p, int N, int G, double D) {

	struct hotel_info tmp = *p; // swap을 위한 임시 구조체

	// --------------- 평판도를 기준으로 내림차순 정렬 -------------------------
	for (struct hotel_info* i = p; i < p + N; i++) {
		for (struct hotel_info* j = i; j < p + N; j++) {
				if (i->score < j->score) { // 현재 호텔의 평판도보다 탐색중인 호텔의 평판도가 더 크면
					tmp = *i; // swap
					*i = *j;
					*j = tmp;
				}
				else if (i->score == j->score) // 평판도가 같다면
					if (strcmp(i->name, j->name) > 0) {
						tmp = *i; // 호텔 이름이 사전상에서 빠른 호텔을 찾으면 스왑
						*i = *j;
						*j = tmp;
					}
		}
	}
	

	for (struct hotel_info* i = p; i < p + N; i++) // 정렬된 구조체 배열을 탐색
		if (G <= i->G && D >= i->D) // 조건을 충족하면
			printf("%s %d %.1lf %.1lf %c\n", i->name, i->G, i->score, i->D, i->bf); // 호텔정보 출력
}
