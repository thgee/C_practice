// ���ǰ�� 3-1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void StringAdd(char arr[], char ch, int index);
int Convertor(char x);

int main() {

	char str[100];
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i + 1] == '\0') break;

		if (Convertor(str[i]) % 2 == 1 && Convertor(str[i + 1]) % 2 == 1) {
			StringAdd(str, '+', i + 1); // Ȧ�� ���̿� + �߰�
			i++;
		}
		else if (Convertor(str[i]) % 2 == 0 && Convertor(str[i + 1]) % 2 == 0) {
			StringAdd(str, '*', i + 1); // ¦�� ���̿� * �߰�
			i++;
		}
	}
	printf("%s", str);

	return 0;
}



void StringAdd(char arr[], char ch, int index){
	// �ش� �迭�� �ش� �ε����� ��Ÿ���� ��ġ�� ��+�� Ȥ�� ��*' �� �����Ѵ�
	for (int i = strlen(arr); i >= index; i--) { // �ι��ڱ��� Ž��
		arr[i + 1] = arr[i];
	}
	arr[index] = ch;
}


int Convertor(char x){
	// ���� ���ڸ� ���ڷ� ��ȯ�Ѵ�.
	return (int)x - '0';
}