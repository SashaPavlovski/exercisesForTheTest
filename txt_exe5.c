#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>

#pragma warning(disable:4996)

typedef struct _car {
	int val;
	char name[100];
	short answer;
}car;

car* seatIbiza = NULL;

void funAnswer();

void exe5() {
	int sum = 0;
	int userResponse;
	scanf("%d", &userResponse);


	 seatIbiza = (car*)malloc(sizeof(car) * userResponse);
	if (!seatIbiza) {
		return 1;
	}
	car* origion = seatIbiza;
	for (int i = 0; i < userResponse; ++i) {

		scanf("%d %s", &seatIbiza->val, seatIbiza->name);
		funAnswer();
		sum = sum + seatIbiza->val;
		++seatIbiza;
	}
	free(origion);
}
void funAnswer() {

	if (seatIbiza->val > 10 && strlen(seatIbiza->name) > 5) {

		seatIbiza->answer = 1;

	}
	else {

		seatIbiza->answer = 0;
	}
}


int main_9() {

	exe5();


	return 0;
}