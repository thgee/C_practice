// 11 - 3 _ 1단계 (과제)

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
	struct hotel_info* best_hotel = NULL; // 최종적으로 조건을 만족하는 호텔을 가리킬 구조체 포인터
	while (1) {
		if (G <= p->G && D >= p->D) {// best_hotel 초기화
			best_hotel = p; break;
		}
			p++;
	}
	for (struct hotel_info* i = p; i < p + N; i++) {
		if (G <= i->G && D >= i->D) { // G 이상의 등급과 D 이하의 거리를 갖는 호텔중
			if (best_hotel->score < i->score)
				best_hotel = i; // 평판도가 높은 호텔을 best_hotel에 저장
			else if (best_hotel->score == i->score) // 평판도가 같다면
				if (strcmp(best_hotel->name, i->name) > 0)
					best_hotel = i; // 호텔 이름이 사전상에서 빠른 호텔을 저장
		}
	}
	printf("%s %d %.1lf %.1lf %c", best_hotel->name, best_hotel->G, best_hotel->score, best_hotel->D, best_hotel->bf);
	// best_hotel의 정보 출력
}
