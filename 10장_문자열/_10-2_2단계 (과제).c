// 10-2_2�ܰ� (����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	char input[500]; // ù ������ �Է¹��� �迭
	char words[50][500]; // �ܾ�� �и��Ͽ� ������ 2���� �迭
	gets(input); // ���� �����Ͽ� �Է�
	char add_word[500]; // �߰��� �ܾ�
	gets(add_word); // �߰��� �ܾ� �Է�

	int num_words = 0; // 2���� �迭�� ����� �ܾ��� ����

	int input_len = strlen(input) + 1; // input ���ڿ��� ���̸� ������ �Լ�
	for (int i = 0, word_len = 0; i < input_len; i++) {
		if (input[i] == ' ' || input[i] == '\0') { // �����̳� �ι��ڸ� ������
			input[i] = '\0'; // ���� �ڸ��� �ι��ڸ� �־���
			strcpy(words[num_words], &input[i] - word_len); // 2���� �迭 words�� ��� Ž���� �ܾ ������
			num_words++; // �ܾ� ���� ī��Ʈ
			word_len = 0; // �ܾ��� ���� ����
			continue;
		}
		word_len++; // �ܾ��� ���� ī��Ʈ
	}


	// --------- �ܾ� �߰� -------------
	int rep = 0;
	for (int i = 0; i < num_words; i++) {
		if (strcmp(words[i], add_word) == 0) rep++; // �ܾ� �ϳ��ϳ� ���ϸ� �ߺ� �˻�
	}
	if (rep == 0){// �ߺ��� �ϳ��� �����ٸ� rep�� 0�� ���̴�.
		strcpy(words[num_words], add_word); // �ܾ �߰�
		num_words++; // �ܾ� �ϳ��� �� �߰������� �ܾ��� ������ ����
	}



// ---------- �� �ܾ� ��� -------------

	for (int i = 0; i < num_words; i++)
		printf("%s\n", words[i]); // words �ȿ� �ִ� �ܾ�� ��� ���


// ----------- ���� ---------------

	// �������� ���
	char tmp_word[300]; // ���� �� �ܾ ������ �ӽ� �迭
	for (int i = 0; i < num_words - 1; i++) { // �ܾ��� ������ŭ �ݺ�
		int fst = i;
		for (int j = i + 1; j < num_words; j++) {
			if(strcmp(words[fst], words[j]) == 1){ // ���������� �Ǿ����� ������
				fst = j; // �� ���� �ܾ��� �ε����� fst�� ����
			}
		}
		strcpy(tmp_word, words[i]); // ����
		strcpy(words[i], words[fst]);
		strcpy(words[fst], tmp_word);
	}



// ----------- �� �������� ���� -----------
	
	char res[10000]; // �ܾ���� �� �������� ��ĥ �迭
	res[0] = '\0'; // res�迭�� ���� �˸��� ���� ù ��° ���ҿ� �ι��ڸ� �־��ش�
		char* p = res; // �ܾ��� �������� ����ų ������
	for (int i = 0; i < num_words; i++) {
		strcat(res, words[i]); // res �迭�� ���ʿ� words�� �� �ܾ���� �̾����
		*(p + strlen(words[i])) = ' '; // �� �ܾ��� ������ ������ �־���
		*(p + strlen(words[i]) + 1) = '\0'; // ������ ����ĭ�� �ι��ڸ� �־���
		p += strlen(words[i]) + 1; // ������ p�� �ܾ��� ���� �ּҸ� ����Ű�� ��
	}
	printf("%s", res); // ���ĵ� ���ڿ� ���

	return 0;
}