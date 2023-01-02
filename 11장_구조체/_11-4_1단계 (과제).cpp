// 11 - 4 _ 1단계 (과제)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct parking_info {
	int num;					// 차량 번호 : 정수형(4자리)
	int call;					// 고객 전화번호 : 정수형(8자리)
	char member;			// 상품 : 문자형(S 혹은 D)
	char join_member;		// 정기권 가입유무 : 문자형(Y 혹은 N) 일일권은 해당사항 없음
	int member_type;	// 종류 : 정수형 7 / 30 / 180 
	int time;					// 주차시간(분) : 정수형
	double cost;			// 요금(원) : 실수형
};

void input(struct parking_info* p, int N);
void compute(struct parking_info* p);
void display(struct parking_info* p, int N);

int main() {

	int N; // 차량의 수
	scanf("%d", &N);
	struct parking_info park[100]; // 주차권 구조체 배열
	input(park, N); // 주차권 정보 입력

	for (struct parking_info* i = park; i < park + N; i++)
		compute(i); // 요금 계산

	display(park, N); // 주차권 정보 출력

	return 0;
}


void input(struct parking_info* p, int N) {

	for (struct parking_info* i = p; i < p + N; i++) {
		scanf("%d%d", &i->num, &i->call); // 차량번호, 전화번호 입력
		getchar(); // 공백 제거
		scanf("%c", &i->member); // 상품 입력
		getchar(); // 공백제거
		if (i->member == 'S') // 정기권 손님이라면
			scanf("%c%d", &i->join_member, &i->member_type); // 정기권 가입유무, 종류 입력
		scanf("%d", &i->time); // 주차시간 입력
	}
}

void compute(struct parking_info* p) {

	p->cost = 0.0; // 금액 초기화



	// 상품이 일일권인 경우 기본요금 --------------------------------------------

	if (p->member == 'D')
		p->cost += 5000; // 4시간 이하까지 기본요금 5000원


	// 초과요금 --------------------------------------------------------------

	if (p->time > 240) {
		p->cost += 200 * ((p->time - 240) / 10); // 4시간 초과 시 10분당 200원 추가
	}



	// 상품이 S이고 정기권에 가입이 안 된 경우 -----------------------------------

	if (p->member == 'S' && p->join_member == 'N') {
		switch (p->member_type) {
		case 7: // 종류가 7일짜리 인 경우
			p->cost += 30000; // 30000원 더해줌
			break;

		case 30: // 종류가 30일짜리 인 경우
			p->cost += 100000; // 100000원 더해줌
			break;

		case 180: // 종류가 180일짜리 인 경우
			p->cost += 500000; // 500000원 더해줌
		}
	}
}
void display(struct parking_info* p, int N) {
	for (struct parking_info* i = p; i < p + N; i++) {
		printf("%d %d %c %.0lf\n", i->num, i->call, i->member, i->cost); // 주차정보 출력
	}
}