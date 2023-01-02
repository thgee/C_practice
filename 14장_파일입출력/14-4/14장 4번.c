#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	char input[21];
	char output[21];
	scanf("%s%s", input, output);

		
	FILE* fp1 = fopen(input, "a");
	FILE* fp2 = fopen(output, "r");

	char buffer[100];

	while (!feof(fp2) ){
		fgets(buffer, 100, fp2);
		fputs(buffer, fp1);
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}
