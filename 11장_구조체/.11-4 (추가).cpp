// .11-4 (추가)cpp

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct student {
	
	char name1[20];
	char name2[20];
	float score;
	int flag;

} student;

int main() {

	int N;
	scanf("%d", &N);
	student st[10];
	char search_name[10];

	// input
	for (int i = 0; i < N; i++)
		scanf("%s%s%f", st[i].name1, st[i].name2, &st[i].score);
	scanf("%s", search_name);

	// search
	int sum = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (strcmp(st[i].name1, search_name) == 0 || strcmp(st[i].name2, search_name) == 0) { // 찾는 이름이 있으면
			st[i].flag = 1;
			sum += st[i].score;
			cnt++;
		}
		else
			st[i].flag = 0;
	}

	float avg = sum / (float)cnt;
	int min_idx;
	float min_diff = 100.0f;
	float diff = 0.0f;
	for (int i = 0; i < N; i++) {
		if (st[i].flag = 1) {
			diff = st[i].score - avg;
			if (diff < 0) diff = -diff;
			if (diff < min_diff) {
				min_diff = diff;
				min_idx = i;
			}
		}
	}
	printf("average = %.2f\n", avg);
	printf("%s %s %.f", st[min_idx].name1, st[min_idx].name2, st[min_idx].score);
	return 0;
}


