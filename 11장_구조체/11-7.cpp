// 11 - 7

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


struct Rank {
	int num;
	int rank;
};

int main() {

	struct Rank nums[10];

	for (int i = 0; i < 10; i++) {
		scanf("%d", &nums[i].num);
		nums[i].rank = 0;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (nums[i].num <= nums[j].num) nums[i].rank++;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (nums[i].rank == 3) printf("%d ", nums[i].num);
	}
	for (int i = 0; i < 10; i++) {
		if (nums[i].rank == 7) printf("%d ", nums[i].num);
	}

	return 0;
}