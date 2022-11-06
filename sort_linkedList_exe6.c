#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>
#include <time.h>

#pragma warning(disable:4996)
void GenerateList();
void addItem(int val);
void PrintList();

typedef struct _Item {

	int Val;
	struct _Item* next;
	struct _Item* prev;


}Item;

extern Item* Head = NULL;
extern Item* Tail = NULL;
Item* curr;



void GenerateList() {

	srand(time(NULL));

	for (int i = 0; i < 10; ++i) {

		addItem(rand()/1000);
		
	}

}




void addItem(int val) {

	Item* move = (Item*)malloc(sizeof(Item));
	if (!move) return;
	
	move->next = NULL;
	move->Val = val;

	if (Head == NULL) {
		Head = move;
		Tail = move;
		move->prev = NULL;
	}
	else {
		Tail->next = move;
		move->prev = Tail;
		Tail = move;
	}

}


void PrintList() {

	Item* print = Head;
	while (print != NULL) {

		printf("%d\n", print->Val);
		print = print->next;

	}
}


void freeItem() {
	Item* freeI = Head;
	Item* oldFreeI = NULL;
	while (freeI){
		oldFreeI = freeI;
		freeI = freeI->next;
		free(oldFreeI);
	}
}


Item* dictionary(int userResponse) {


	Item* checkMove = Head;
	while (checkMove) {

		if (checkMove->Val == userResponse) return checkMove;

		checkMove = checkMove->next;
	}
	printf("not have this number");
	return NULL;
}


Item* ChangeVal(int new, int old) {

	Item* oldStruct = dictionary(old);
	oldStruct->Val = new;
	return oldStruct;

}

void ResetList() {
	if (!Head) {
		return;
	}
	freeItem();
	Head = NULL;
	Tail = NULL;
}

Item* biggest(int val){

	Item* current = Head;
	int bigger = val;
	while (current) {
		if (current->Val > bigger)return current;
		current = current->next;
	}
	return NULL;
}








int main_10(){

	GenerateList();
	PrintList();
	dictionary(4);


	return;
}