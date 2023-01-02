//_9-2 (추가)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sort(int N, int id[], double avg[]);

int main() {

	int N;
	scanf("%d", &N);
	int id[100], kor[100], math[100];
	double avg[100];
	int* pi = id, * pk = kor, * pm = math;
	double* pa = avg;
	for (pi; pi < id + N; pi++, pk++, pm++, pa++) {
		scanf("%d%d%d", pi, pk, pm);
		*pa = (*pk + *pm) / 2.0;
	}

	sort(N, id, avg);
	pi = id;
	pa = avg;
	for (pi; pi < id + N; pi++, pa++)
		printf("%d %.1lf\n", *pi, *pa);

		return 0;
	
}

// 내림차순 정렬
void sort(int N, int id[], double avg[]) {
	int* pi = id;
	double* pa = avg;
	int* max_id;
	double* max_avg;

	for (pi; pi < id + N - 1; pi++, pa++) {
		double* max_avg = pa;
		int* max_id = pi;
		double* qa = pa;
		
		for (int *qi = pi; qi < id + N; qi++) {
			if (*max_avg < *qa) {
				max_avg = qa;
				max_id = qi;
			}
			qa++;
		}

		// 스왑
		int tmp_id = *pi;
		*pi = *max_id;
		*max_id = tmp_id;
		
		double tmp_avg = *pa;
		*pa = *max_avg;
		*max_avg = tmp_avg;
	}
}
