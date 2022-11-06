#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>

#pragma warning(disable:4996)

int main_7() {
	FILE* f = fopen("q4.txt", "r");
	FILE* f1 = fopen("q4.txt", "r");
	if (!f1) {
		return;
	}

	if (!f) {
		return;
	}
	char temp = "";
	char tempInt = "";
	int* number;
	char* number1;
	int forInt;
	temp = fgetc(f);
	while ((temp = fgetc(f)) != EOF) {

		tempInt = fgetc(f1);

		if (temp == 'c') {
		
			number1 = (char*)malloc(sizeof(char) *(tempInt-'0'));
			if (!number1) {
				return;
			}
			char* origin = number1;
			for (int i = 1; i <= tempInt-'0'; ++i) {
				*number1 = (char)i;
				number1++;
			}
			 
			free(origin);
			tempInt = fgetc(f1);

		}
		else if (temp == 'i') {

			number = (int*)malloc(sizeof(int) *( tempInt-'0'));
			if (!number) {
				return;
			}
			int *origin = number;

			for (int i = 0; i < tempInt-'0'; ++i) {
				*number = i;
				number++;

			}
			free(origin);
			tempInt = fgetc(f1);

		}
		temp = fgetc(f);

	}
	fclose(f);
	fclose(f1);
	return 0;
}