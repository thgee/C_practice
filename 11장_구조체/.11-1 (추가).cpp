// .11-1 (�߰�)cpp

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
		record[i].day = tmp % 100; // month�� day �ʱ�ȭ
		record[i].month = tmp / 100;
		for(int j = 0;;j++){
			scanf("%d", &record[i].sale[j]);
			if (record[i].sale[j] == 0) break; // ���ǹ�ȣ�� 0���̸� Ż��
		}
	}

	int month, day, item_idx; // ã�� ��¥�� ���ǹ�ȣ
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


