//7-4 (2차원)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x[3][3], y[2][2];

	//-------------입력----------------
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d" , &x[i][j]);

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			scanf("%d", &y[i][j]);

	//-------------출력----------------

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			printf(" %d", x[i][j]);
		printf("\n");
	}


	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			printf(" %d", y[i][j]);
		printf("\n");
	}

	// ------------ search --------------
	int cnt = 0;
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++) {
			int a = 0,b = 0;
			if (x[i][j] == y[a][b]) {
				j++;
				b++;
				if (x[i][j] == y[a][b]) {
					i++;
					a++;
					if (x[i][j] == y[a][b]) {
						j--;
						b--;
						if (x[i][j] == y[a][b]) {
							cnt++;
							printf("%d %d", i - 1, j);
						}
					}
				}
			}
		}
			
	if (cnt == 0) printf("none");

	return 0;
}

