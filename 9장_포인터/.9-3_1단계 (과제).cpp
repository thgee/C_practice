// .9-3-1 (����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isSmall(char ch); // ���ڰ� �ҹ������� �Ǵ��ϴ� �Լ�

int main() {

	char str[100];
	int len = 0; // �迭�� ���̸� ��Ÿ���� ����

	// input
	char* p_str = str; // str�� ����Ű�� ������ p_str ����
	while (1) { // ���ѷ���
		scanf("%c", p_str);
		if (*p_str == '#') break; // # ���ڸ� �Է¹����� ���ѷ��� ����
		p_str++;
		len++; // �迭���� + 1
	}

	int max = 0, cnt = 0; // max : ���� �� �ܾ��� ���� cnt : ���� �ܾ��� ����
	for (p_str = str; p_str <= str + len; p_str++) {
		if (isSmall(*p_str)) { // ���� ����Ű�� ���ڰ� �ҹ����̸�
			printf("%c", *p_str); // �� ���ڸ� ���
			cnt++; // �ܾ� ���� + 1
		}
		else {
			if (isSmall(*(p_str + 1))) printf("\n"); // ���ο� �ܾ� ���۽� ����
			if (max < cnt) {  // ���� �ܾ��� ���̰� ���� �� �ܾ��� ���̺��� ���
				max = cnt; // ���� �� ���̸� ����
			}
			cnt = 0; // �ܾ���� �ʱ�ȭ
		}
	}

	printf("\n%d", max); // ���� �� �ܾ��� ���� ���

	return 0;
}


int isSmall(char ch) {
	if('a' <= ch && 'z' >= ch) return 1; // �ҹ����̸� true ��ȯ
	return 0;
}
