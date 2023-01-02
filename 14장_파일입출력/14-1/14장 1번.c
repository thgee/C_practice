#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {

	int num;
	FILE* fp = fopen("data.txt", "w");
	while (1) {
		fscanf(stdin, "%d", &num);
		if (feof(stdin)) break;
		fprintf(fp, "%d\n", num);
	}
	fclose(fp);

	int arr[3];
	int sum = 0, cnt = 0;
	double avg;
	fp = fopen("data.txt", "r");
	while (1) {
		
		fscanf(fp, "%d", &arr[cnt]);
		if (feof(fp)) break;
		sum += arr[cnt];
		cnt++;
	}
	avg = sum / 3.0f;

	fclose(fp);

	printf("%d\n%d\n%.2lf", cnt, sum, avg);

	return 0;
}