//10-4 (����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int s_check(char* p, char* q);

int main() {

	int M, K1, K2;
	scanf("%d%d%d", &M, &K1, &K2); // M, K1, K2 �Է�
	getchar(); // ���ۿ� ���� ���๮�� ����


	for (int i = 0; i < M; i++) { // M�� �Է¹���
		char str[201] = { '\0' }; // �迭�� ���Ҹ� �ι��ڷ� ��� �ʱ�ȭ
		int cnt = 0; // �ҹ��� ���� �ʱ�ȭ

		gets(str); // ������ �����Ͽ� �Է¹���

		cnt = s_check(str + K1, str + K2); // K1��° �ּҿ� K2��° �߼Ҹ� ���ڷ� �־��־� �ҹ��� ������ �޾ƿ�
		if (cnt == 0) continue; // �ҹ��ڰ� ������ ��¾���
		printf("%d\n", cnt); // �ش� ���� �ҹ��� ���� ���

	}
	return 0;
}

int s_check(char* p, char* q) {

	int cnt_small = 0;
	for (char* i = p; i <= q; i++) { // ������ i�� p���� q���� ����Ű�� ��ȯ��
		if (*i >= 'a' && *i <= 'z') cnt_small++; // i�� ����Ű�� ���ڰ� �ҹ����̸� cnt_small ����
	}
	return cnt_small; // �ҹ��� ���� ��ȯ
}
