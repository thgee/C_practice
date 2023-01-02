#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	char input[21];
	char output[21];
	scanf("%s%s", input, output);
	

	FILE* fp1 = fopen(input, "r");
	FILE* fp2 = fopen(output, "w");
		
	char buffer[100];

	while (!feof(fp1)) {
		fgets(buffer, 100, fp1);
		fputs(buffer, fp2);
	}

	
	fclose(fp1);
	fclose(fp2);
	return 0;
}
