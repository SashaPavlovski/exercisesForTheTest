#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>

#pragma warning(disable:4996)



int main_1(){

	FILE* f = fopen("file.txt","rb");
	if (!f) {
		return;
	}
	char temp = "";
	int count = 0;
	while (fread(&temp, sizeof(char), 1, f)) {
		if(temp == '*')
		count++;
	}
	fclose(f);




	return 0;

}