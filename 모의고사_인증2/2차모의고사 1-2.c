// 2�����ǰ�� 1 - 2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	int N, M1, M2;
	char str[20][101];

	scanf("%d%d%d", &N, &M1, &M2);
	getchar();
	
	// ---------- ���ڿ� �Է� --------------
	for (int i = 0; i < N; i++) {
		gets(str[i]);
	}

	// ----------- ���ڿ��� ���̸� �������� �������� ���� ----------
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			char tmp[101];
			if (strlen(str[j + 1]) > strlen(str[j])) { // ��������
				strcpy(tmp, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], tmp);
			}
		}
	}

	// ---------- ���� ª�� ������ �ε��� ���� ----------
	int shortest_idx;
	for (int i = 0; i < N; i++) {
		if (strlen(str[N - 1]) == strlen(str[i])) {
			shortest_idx = i;
			break;
		}
	}

	// ------------- ���� �� ���ڿ��� M1, ���� ª�� ���ڿ��� M2��° �ܾ ���� temp1, temp2�� ���� ----------
	char temp1[101], temp2[101];
	for (int j = 0, idx = 0; j <= strlen(str[0]); j++) { // j�� ù��° ���ڿ��� �ι��ڱ��� Ž��
		if (idx == M1) { // M1��°�� �ܾ��� ù���ڿ� j�� �����ϸ�

			// ----------- M1��° �ܾ��� ���� ���� ------------
			for (int k = j;; k++) { // k�� j���� Ž���ϸ鼭
				if (str[0][k] == ' ' || str[0][k] == '\0') { // k�� �ܾ��� �� + 1���� �����ϸ�

					int len = k - j; // �ܾ��� ���� ����
					strncpy(temp1, &str[0][j], len); // temp1�� M1��° �ܾ� ����
					temp1[len] = '\0';
					j = k;
					break;
				}
			}
		}
		if (str[0][j] == ' ' || str[0][j] == '\0') // �����̳� �ι��� ������
			idx++;
	}

	for (int j = 0, idx = 0; j <= strlen(str[shortest_idx]); j++) { // j�� ù��° ���ڿ��� �ι��ڱ��� Ž��
		if (idx == M2) { // M2��°�� �ܾ��� ù���ڿ� j�� �����ϸ�

			// ----------- M2��° �ܾ��� ���� ���� ------------
			for (int k = j;; k++) { // k�� j���� Ž���ϸ鼭
				if (str[shortest_idx][k] == ' ' || str[shortest_idx][k] == '\0') { // k�� �ܾ��� �� + 1���� �����ϸ�
					int len = k - j; // �ܾ��� ���� ����
					strncpy(temp2, &str[shortest_idx][j], len); // temp2�� M2��° �ܾ� ����
					temp2[len] = '\0';
					j = k;
					break;
				}
			}
		}
		if (str[shortest_idx][j] == ' ' || str[shortest_idx][j] == '\0') // �����̳� �ι��� ������
			idx++;
	}

	// ------------- temp1�� temp2�� ������ ���� ������� res�� ���� -----------
	char res[201];
	if (strcmp(temp1, temp2) < 0) {
		strcpy(res, temp1);
		strcat(res, temp2);
	}
	else {
		strcpy(res, temp2);
		strcat(res, temp1);
	}

	// ------------- ��� ------------
	printf("%s\n%s\n", str[0], str[shortest_idx]);
	printf("%s", res); // �ѹ��� ��¹����� ���

	return 0;
}

/*
5 4 2
book desk pencil paper
orange apple banana lemon grape
red yellow green orange blue white black
candy cake icecream
july august september october november december
*/