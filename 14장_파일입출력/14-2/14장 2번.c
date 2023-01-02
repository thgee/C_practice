#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {

	FILE* fp = fopen("test1.txt", "r");
	char buffer[10];

	while (!feof(fp))
		fgets(buffer, 10, fp);

	fclose(fp);

	// 대소문자 변환
	int dif = 'a' - 'A';
	for (int i = 0; i < 10; i++) {
		if (buffer[i] >= 'A' && buffer[i] <= 'Z')
			buffer[i] += dif;
		
		else if (buffer[i] >= 'a' && buffer[i] <= 'z')
			buffer[i] -= dif;
	}


	fp = fopen("test2.txt", "w");
	fputs(buffer, fp);

	fclose(fp);

	return 0;
}