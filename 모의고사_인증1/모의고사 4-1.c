// ���ǰ�� 4-1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main() {

	char str[500] = {0}, res[500] = {0};
	char from[100], to[100];
	gets(str);
	scanf("%s%s", from, to);

	int start_res = 0;
	int start_str = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (strncmp(&str[i], from, strlen(from)) == 0) { // ���ڰ� ���ٸ�
			
			str[i] = '\0'; // str���� from�� ù ���� �ڸ��� �ι��ڸ� ����
			strcpy(&res[start_res], &str[start_str]);
			start_res += strlen(&str[start_str]); // res�� �ε���
			strcat(res, to);
			start_res += strlen(to);
			start_str = i + strlen(from);
			//i += strlen(from) - 1;
		}
		if (i == len - 1) { // str�� ���� �����ϸ�
			strcat(res, &str[start_str]);

		}
	}

	printf("%s", res);

	return 0;
}
