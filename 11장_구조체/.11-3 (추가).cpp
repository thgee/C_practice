// .11-3 (�߰�)cpp

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
	char name[3][100]; // 3���� �Ĵ� �̸��� ������ �迭
	int min_diff = 6000; // �Ĵ�� �ݾ��� ���̰� ���� ���� ��� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (i != j && j != k && i != k) { // ���� ��� �ٸ� �Ĵ翡�� �Ծ����
					int sum = re[i].breakfast + re[j].lunch + re[k].dinner;
					int diff = cost - sum;
					if (diff < 0) continue; // �Ĵ뺸�� �ݾ��� Ŀ���� ����
					if (min_diff > diff) { // �Ĵ�� �ݾ��� �� ������
						strcpy(name[0], re[i].name); // ��ħ, ����, ���� �̸� ����
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


