//_12-2_3�ܰ� (����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main() {

	char A[101], B[101];
	gets(A); // ���ڿ� A, B �Է�
	gets(B);

	// ------------ �ܾ��� ���� ���� -------------

	int num1 = 0, num2 = 0; // num1 : A�� �ܾ� ����		num2 : B�� �ܾ� ����
	for (int i = 0; i <= strlen(A); i++) {
		if (A[i] == ' ' || A[i] == '\0') { // �����̳� �ι��ڸ� ������
			num1++; // �ܾ� ���� ī��Ʈ
		}
	}
	for (int i = 0; i <= strlen(B); i++) {
		if (B[i] == ' ' || B[i] == '\0') { // �����̳� �ι��ڸ� ������
			num2++; // �ܾ� ���� ī��Ʈ
		}
	}


	// ------------- 2���� �迭 �����Ҵ� --------------

	char** str1 = (char**)malloc(sizeof(char*) * num1); // A ���ڿ��� �ܾ� ���� ��ŭ ������ �迭 �����Ҵ�
	if (str1 == NULL) { // �����Ҵ� ���� ���� üũ
		printf("Not enough momory!");
		return -1;
	}

	char** str2 = (char**)malloc(sizeof(char*) * num2); // B ���ڿ��� �ܾ� ���� ��ŭ ������ �迭 �����Ҵ�
	if (str2 == NULL) { // �����Ҵ� ���� ���� üũ
		printf("Not enough momory!");
		return -1;
	}


	// ---------- 2���� �迭 �ȿ� 1���� ���ڿ� �����Ҵ� ------------


	int length = 0; // �ܾ��� ����
	for (int i = 0, j = 0; i <= strlen(A); i++) {
		if (A[i] != ' ' && A[i] != '\0') { // A�� ���鼭 �����̳� �ι��ڰ� �ƴ϶��
			length++; // �ܾ��� ���� ����
		}
		else { // �����̳� �ι��ڸ� ������
			str1[j] = (char*)malloc((length + 1) * sizeof(char)); // �ܾ��� ���� + 1 ��ŭ�� ũ�⸦ �����Ҵ�
			if (str1[j] == NULL) { // �����Ҵ� ���� ���� üũ
				printf("Not enough momory!");
				return -1;
			}
			j++; // ������ ������ �ε��� ����
			length = 0; // �ܾ��� ���� �ʱ�ȭ
		}
	}


	for (int i = 0, j = 0; i <= strlen(B); i++) {
		if (B[i] != ' ' && B[i] != '\0') { // B�� ���鼭 �����̳� �ι��ڰ� �ƴ϶��
			length++; // �ܾ��� ���� ����
		}
		else { // �����̳� �ι��ڸ� ������
			str2[j] = (char*)malloc((length + 1) * sizeof(char)); // �ܾ��� ���� + 1 ��ŭ�� ũ�⸦ �����Ҵ�
			if (str2[j] == NULL) { // �����Ҵ� ���� ���� üũ
				printf("Not enough momory!");
				return -1;
			}
			j++; // ������ ������ �ε��� ����
			length = 0; // �ܾ��� ���� �ʱ�ȭ
		}
	}




	// ------------- 2�����迭�� �ܾ� ���� ---------------

	for (int i = 0, j = 0, k = 0; i <= strlen(A); i++) { // i�� A���ڿ��� �ι��ڱ��� Ž��

		if (A[i] != ' ' && A[i] != '\0') { // �����̳� �ι��ڰ� �ƴ϶��
			str1[k][j] = A[i]; // str1�� ����
			j++;
		}
		else { // �����̳� �ι��ڸ� ������
			str1[k][j] = '\0'; // �ܾ��� ���� �ι��ڸ� �ٿ��ְ�
			k++; // ���� �ܾ�� �Ѿ
			j = 0;
		}
	}

	for (int i = 0, j = 0, k = 0; i <= strlen(B); i++) { // i�� B���ڿ��� �ι��ڱ��� Ž��
		if (B[i] != ' ' && B[i] != '\0') { // �����̳� �ι��ڰ� �ƴ϶��
			str2[k][j] = B[i]; // str1�� ����
			j++;
		}
		else { // �����̳� �ι��ڸ� ������
			str2[k][j] = '\0'; // �ܾ��� ���� �ι��ڸ� �ٿ��ְ�
			k++; // ���� �ܾ�� �Ѿ
			j = 0;
		}
	}



	// ----------- str2 �������� ���� ----------

	for (int i = 0; i < num2; i++) {
		for (int j = 0; j < num2 - i - 1; j++) {
			char* temp; // swap�� ���� �ӽ� ����
			if (strlen(str2[j]) < strlen(str2[j + 1])) { // ���̰� ū ������� ��������
				temp = str2[j];
				str2[j] = str2[j + 1];
				str2[j + 1] = temp;
			}
			if (strlen(str2[j]) == strlen(str2[j + 1])) // ���̰� ���ٸ�
				if (strcmp(str2[j], str2[j + 1]) > 0) { // ���������� ����
					temp = str2[j];
					str2[j] = str2[j + 1];
					str2[j + 1] = temp;
				}
		}
	}


	// -------------- �ռ��� ���-------------------

	for (int i = 0; i < num2; i++) { // str2�� �ܾ� �ϳ��� ���
		int flag = 0; // �ش� �ռ�� ����ߴ��� �˷��ִ� �÷���
		for (int j = 0; j < num1; j++) { // str1�� Ž���Ѵ�.
			if (strncmp(str2[i], str1[j], strlen(str1[j])) == 0) { // str1�� �ܾ str2�� ���ԵǾ� �ִٸ�
				for (int k = 0; k < num1; k++) { // str1�� �ѹ��� �� ����.
					if (j == k) // ���� �ܾ�� �̷���� �ռ���� ������� �ʴ´�.
						continue;
					if (strcmp(str2[i] + strlen(str1[j]), str1[k]) == 0) { // str1�� �ܾ� �ΰ��� str2�� ���Եȴٸ�
						printf("%s\n", str2[i]); // �ش� �ռ��� ���
						flag = 1; // �ռ�� ��������� flag�� 1 ����
					}
				}
			}
			if (flag == 1)  // �ռ�� ����ߴٸ�
				break; // ���� �ܾ�� �Ѿ
		}
	}



	// --------------- �޸� ���� --------------------

	for (int i = 0; i < num1; i++) {
		if (str1[i] != NULL)
			free(str1[i]);
	}

	for (int i = 0; i < num2; i++) {
		if (str2[i] != NULL)
			free(str2[i]);
	}

	if (str1 != NULL)
		free(str1);

	if (str2 != NULL)
		free(str2);


	return 0;
}


