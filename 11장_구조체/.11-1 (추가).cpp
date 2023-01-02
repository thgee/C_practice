// .11-1 (추가)cpp

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct record {
	int month;
	int day;
	int sale[20];
}; typedef struct record re;


int main() {
	

	int N;
	scanf("%d", &N);
	re record[10];
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		record[i].day = tmp % 100; // month와 day 초기화
		record[i].month = tmp / 100;
		for(int j = 0;;j++){
			scanf("%d", &record[i].sale[j]);
			if (record[i].sale[j] == 0) break; // 물건번호가 0번이면 탈출
		}
	}

	int month, day, item_idx; // 찾는 날짜와 물건번호
	scanf("%d%d%d", &month, &day, &item_idx);
	

	int cnt;
	for (int i = 0; i < N; i++) {
		cnt = 0;
		if (record[i].month == month && record[i].day == day) {
			for (int j = 0;; j++) {
				if (record[i].sale[j] == item_idx) cnt++;
				if (record[i].sale[j] == 0) break;
			}
			break;
		}
	}
	
	printf("%d", cnt);

	return 0;

}


