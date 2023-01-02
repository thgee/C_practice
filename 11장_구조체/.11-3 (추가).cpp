// .11-3 (추가)cpp

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct rest {
	char name[100];
	int breakfast;
	int 	lunch;
	int 	dinner;
}rest ;

int main() {

	int N;
	rest re[10];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s%d%d%d", re[i].name, &re[i].breakfast, &re[i].lunch, &re[i].dinner);

	int cost;
	scanf("%d", &cost);

	int max_sum = 0;
	char name[3][100]; // 3개의 식당 이름을 저장할 배열
	int min_diff = 6000; // 식대와 금액의 차이가 가장 적을 경우 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (i != j && j != k && i != k) { // 세끼 모두 다른 식당에서 먹어야함
					int sum = re[i].breakfast + re[j].lunch + re[k].dinner;
					int diff = cost - sum;
					if (diff < 0) continue; // 식대보다 금액이 커지면 제외
					if (min_diff > diff) { // 식대와 금액이 더 가까우면
						strcpy(name[0], re[i].name); // 아침, 점심, 저녁 이름 저장
						strcpy(name[1], re[j].name);
						strcpy(name[2], re[k].name);
						max_sum = sum;
						min_diff = diff;
					}
				}
			}
		}
	}

	for (int i = 0; i < 3; i++)
		printf("%s\n", name[i]);
	printf("%d", max_sum);

	return 0;

}


