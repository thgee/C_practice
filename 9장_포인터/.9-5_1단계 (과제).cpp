// 9-5-1 (����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {

	char str[1000];
	char* p = str; // str �迭�� ����Ű�� ������
	int len = 0; // �迭�� ����

	// ------------- input ---------------
	while (true) { // ���ѷ���
		scanf("%c", p);
		if (*p == '.' || *p == '?' || *p == '!') break; // .?!�� �Է¹����� Ż��
		p++;
		len++; // �迭���� ����
	}

	int cnt = 0;
	for (p = str + len - 1; p >= str; p--) { // �迭�� �ں��� Ž��
		if (*p == ' ') { // ������ ������
			for (char* q = p + 1; q <= p + cnt; q++) 
				printf("%c", *q); // ���� ������ �ִ� �ܾ ���
			printf(" "); // ����
			cnt = 0;
			continue;
		}

		if (p == str) // p�� str�� ���������� �����ϸ�
			for (char* q = str; q <= str + cnt; q++)
				printf("%c", *q); // �� ó�� �ܾ� ���

		cnt++; // �ܾ� ���ڼ� ī��Ʈ
	}

	printf("%c", *(str + len)); // .?! ���

	return 0;
}

