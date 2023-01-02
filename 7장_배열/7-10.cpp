// 7-10

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void setRank(int arr[], int rank[]);

int main() {

	int arr[5], rank[5] = { 0 };
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	setRank(arr, rank);

	for (int i = 0; i < 5; i++)
		printf("%d=r%d ", arr[i], rank[i] + 1);


	return 0;
}


void setRank(int arr[], int rank[]) {

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (arr[i] < arr[j]) rank[i] ++;

}
