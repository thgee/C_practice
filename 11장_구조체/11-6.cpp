// 11 - 6

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student {
	int sex;
	int weight;
	int height;
};

int main() {

	int N;
	scanf("%d", &N);
	struct student std[20];
	int grade[3] = {0};

	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &std[i].sex, &std[i].weight, &std[i].height);
	}

	for (int i = 0; i < N; i++) {
		if(std[i].sex == 1){ // 남자	

			if (std[i].weight < 60) {
				if (std[i].height < 165) grade[0]++;
				else if (std[i].height < 175) grade[1]++;
				else grade[2]++;
			}
			else if (std[i].weight < 70) {
				if (std[i].height < 165) grade[2]++;
				else if (std[i].height < 175) grade[0]++;
				else grade[1]++;
			}
			else {
				if (std[i].height < 165) grade[1]++;
				else if (std[i].height < 175) grade[2]++;
				else grade[0]++;
			}
		}

		if (std[i].sex == 2) { // 여자	

			if (std[i].weight < 50) {
				if (std[i].height < 165) grade[0]++;
				else if (std[i].height < 175) grade[1]++;
				else grade[2]++;
			}
			else if (std[i].weight < 60) {
				if (std[i].height < 165) grade[2]++;
				else if (std[i].height < 175) grade[0]++;
				else grade[1]++;
			}
			else {
				if (std[i].height < 165) grade[1]++;
				else if (std[i].height < 175) grade[2]++;
				else grade[0]++;
			}
		}
	}

	for (int i = 0; i < 3; i++)
		printf("%d ", grade[i]);

	return 0;
}