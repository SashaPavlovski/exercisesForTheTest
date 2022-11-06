#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>

#pragma warning(disable:4996)



void exe4() {
	char fileName[20] = "";
	int userResponse;
	char str[10] = "";

	scanf("%d", &userResponse);

	for (int i = 1; i <= userResponse; ++i) {
		sprintf(fileName, "file%d.txt", i);
		FILE* f = fopen(fileName, "w");
		if (!f) {
			return 1;
		}
		for (int a = 0; a < i; ++a) {
			str[a] = '*';
		}

		fwrite(&str, sizeof(char) * i, 1, f);


		fclose(f);
	}


}

int main_8() {

	exe4();

	return 0;
}