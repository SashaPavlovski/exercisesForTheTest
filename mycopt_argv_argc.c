#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>
#include <time.h>

#pragma warning(disable:4996)

void testCopy(char* fileSourse, char* fileDestination) {

	FILE* f = fopen(fileSourse,"r");
	if (!f) return 1;

	char temp;
	int count = 0;
	while (fread(&temp,sizeof(char),1, f)) {
		++count;
	}
	fclose(f);
	f = fopen(fileSourse, "r");
	if (!f) return 1;
	char* contents = (char*)malloc(count);
	if (!contents) return 1;
	fread(contents, sizeof(char)* count, 1, f);
	fclose(f);
	f = fopen(fileDestination, "w");
	if (!f) return 0;
	fputs(contents, f);
	fclose(f);
	free(contents);
}

int main(int argc, char* argv[]) {
	printf("start\n");
	testCopy(argv[1], argv[2]);
	printf("end\n");
	return 0; 
}