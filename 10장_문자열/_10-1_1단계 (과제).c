//10-1_1�ܰ� (����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void changeChar(char ch, int N); // �빮��, �ҹ����� ��츦 ������ ����ϴ� �Լ�
void printRepAlpha(int num, int N); // num��°�� �빮�ڸ� N�� ����ϴ� �Լ�



int main() {

	char str[22];
	int N;
	scanf("%s", str);
	scanf("%d", &N);

	char num[3] = "aa"; // ���ڰ� ������ �����ص� �迭, ���ڿ� "aa"�� �ʱ�ȭ
	for (int i = 0, j = 0; i < strlen(str); i++) { // ���ڿ��� ���̸�ŭ �ݺ�

		if (str[i] >= '0' && str[i] <= '9') { // ������ ��
			num[j] = str[i];  // num�迭�� ���� ���� ����
			j++; // ���ڸ� ������ ���� �����Ƿ� ���� �ڸ����� Ž���ϱ� ���� j�� ������Ŵ
		}
		else { // ���ڰ� �ƴ� ��
			j = 0;
			if (atoi(num) != 0) // num�� 'a' �� �ƴ� ������ ���������
				printRepAlpha(atoi(num), N); // num�� ����ִ� ���� ��°�� �빮�ڸ� N�� ���
			changeChar(str[i], N); // ���� �ε����� �ش��ϴ� ���ڸ� ����Լ��� �Ѱ���
			num[0] = 'a'; // num �ʱ�ȭ
			num[1] = 'a';
		}

		if(str[i + 1] == '\0' && atoi(num) != 0) // ���ڿ��� �������� ���ڷ� ������ ���
			printRepAlpha(atoi(num), N); // num�� ����ִ� ���� ��°�� �빮�ڸ� N�� ���

	}

	return 0;
}

void changeChar(char ch, int N) {// �빮��, �ҹ����� ��츦 ������ ����ϴ� �Լ�

	if (ch >= 'A' && ch <= 'Z') printf("%c", ch + N); // �빮�ڸ� �ƽ�Ű �ڵ� ������ N�� ���� ���ڸ� ���
	else if (ch >= 'a' && ch <= 'z') printf("%c", ch - N); // �ҹ��ڸ� �ƽ�Ű �ڵ� ������ N�� �� ���ڸ� ���
	else printf(" "); // �� �� ���� ���
}


void printRepAlpha(int num, int N) { // num��°�� �빮�ڸ� N�� ����ϴ� �Լ�
	for (int i = 0; i < N; i++) {
		printf("%c", 'A' + num - 1);
	}
}


