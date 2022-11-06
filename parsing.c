//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <conio.h>
//
//#pragma warning(disable: 4996)
//void sumOfString() {
//
//	char numbers[50] = { "123,456,789,1,2,3,4,5,6,7,2000" };
//	char* token = strtok(numbers,",");
//	int sum = atoi(token);
//	while (token != NULL) {
//
//		token = strtok(NULL, ",");
//		if (token != NULL) {
//			sum += atoi(token);
//		}
//	}
//
//	printf("%d", sum);
//
//}
//
//void fullName() {
//
//	char fullNameWithSpace[20] = "";
//	char fullNameWithALinebreak[20] = "";
//	gets(fullNameWithSpace);
//	char* token = strtok(fullNameWithSpace, " ");
//	strcat(fullNameWithALinebreak, token);
//	strcat(fullNameWithALinebreak, "\n");
//	token = strtok(NULL, " ");
//	strcat(fullNameWithALinebreak, token);
//	printf("%s", fullNameWithALinebreak);
//
//}
//
//void fullNameWithToNames() {
//
//	char fullNameWithSpace[20] = "";
//	gets(fullNameWithSpace);
//	char* token = strtok(fullNameWithSpace, " ");
//	printf("%s\n", token);
//	while (token != NULL) {
//		token = strtok(NULL, " ");
//
//		if (token != NULL) {
//			printf("%s ", token);
//			
//		}
//
//	}
//
//}
//
//void parsing() {
//
//	FILE* f = fopen("oscar_age_female.txt", "rb");
//	if (!f) return 1;
//	char string[1000] = "";
//
//	fgets(string, 1000, f);
//
//	while ((fgets(string, 1000, f))) {
//
//		char* index = strtok(string, ",");
//		char* Year = strtok(NULL, ",");
//		char* Age = strtok(NULL, ",");
//		char* garbage = strtok(NULL, "\"");
//		char* Name = strtok(NULL, "\"");
//		garbage = strtok(NULL, "\"");
//		char* Movie = strtok(NULL, "\"");
//		
//		printf("The Oskar Goes to %s  at %s  Movie - %s\n", Name, Year, Movie);
//
//	}
//
//
//	fclose(f);
//
//}
//
//
//
//
//int main() {
//
//	sumOfString();
//	fullName();
//	fullNameWithToNames();
//	parsing();
//	return 0;
//}