//10-1_2�ܰ� (����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// ���ڸ� ������ ��ȯ�Ͽ� res�迭�� �־��ִ� �Լ�
void changeStr(char str[], char res[], int N);




int main() {

	char str1[22];
	char str2[22];
	gets(str1); // ������ �����Ͽ� �Է¹޾ƾ� ��
	gets(str2); // ������ �����Ͽ� �Է¹޾ƾ� ��

	char res1[500]; // str1�� ��ȯ��Ų ���ڿ� res1
	char res2[500]; // str2�� ��ȯ��Ų ���ڿ� res2

	
	int cnt = 0; // ���� �Ұ����� �Ǵ��ϱ� ���� ����
	for (int i = 1; i < 27; i++) { // N�� ������ 1~26���� �־��� (N�� 26���� ��ȯ�ϸ鼭 �Լ��� ����, ��ȯ�� �������� �Ǵ�)
		changeStr(str1, res1, i); // str1�� ��ȯ���� res1�� ���� (�Լ��̿�)
		changeStr(str2, res2, i); // str2�� ��ȯ���� res2�� ����
		if (strcmp(res1, str2) == 0) { // str1�� ������ res1�� str2�� ������ 1�� ��� �� ���� 
			printf("%d", 1); break;
		} 

		if (strcmp(res2, str1) == 0) { // str2�� ������ res2�� str1�� ������ 2�� ��� �� ���� 
			printf("%d", 2); break;
		}

		cnt++; // for���� Ż������ �������� cnt ����
	}

		if(cnt == 26) printf("%d", 0); // ���� �Ұ����ϸ� 0�� ���

	return 0;
}


void changeStr(char str[], char res[], int N)
{
	int idx = 0;
	char num[3] = "aa"; // ���ڰ� ������ �����ص� �迭, ���ڿ� "aa"�� �ʱ�ȭ
	for (int i = 0, j = 0; i < strlen(str); i++) { // ���ڿ��� ���̸�ŭ �ݺ�

		if (str[i] >= '0' && str[i] <= '9') { // ������ ��
			num[j] = str[i];  // num�迭�� ���� ���� ����
			j++; // ���ڸ� ������ ���� �����Ƿ� ���� �ڸ����� Ž���ϱ� ���� j�� ������Ŵ
		}
		else { // ���ڰ� �ƴ� ��
			j = 0;
			if (atoi(num) != 0) { // num�� 'a' �� �ƴ� ������ ���������
				for (int i = 0; i < N; i++) { 
					res[idx] = 'A' + atoi(num) - 1; // num�� ����ִ� ���ڹ�°�� �빮�ڸ� N�� res�� ����
					idx++; // res �ε��� ����
				}
			}
			if (str[i] >= 'A' && str[i] <= 'Z') res[idx] = str[i] + N; // �빮�ڸ� �ƽ�Ű �ڵ� ������ N�� ���� ���ڸ� ����
			else if (str[i] >= 'a' && str[i] <= 'z') res[idx] = str[i] - N; // �ҹ��ڸ� �ƽ�Ű �ڵ� ������ N�� �� ���ڸ� ����
			else res[idx] = ' '; // �� �� ���� ����
			idx++; // res �ε��� ����
			num[0] = 'a'; // num �ʱ�ȭ
			num[1] = 'a';
		}

		if (str[i + 1] == '\0' && atoi(num) != 0) // ���ڿ��� �������� ���ڷ� ������ ���
		for (int i = 0; i < N; i++) { // num�� ����ִ� ���� ��°�� �빮�ڸ� N�� res�� ����
			res[idx] = 'A' + atoi(num) - 1;
			idx++; // res �ε��� ����
		}
	}
	res[idx] = '\0'; // res�� ������ �ε����� �ι��� ����
}

