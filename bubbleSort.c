#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>
#include <time.h>

#pragma warning(disable:4996)



typedef struct _Item {

	int val;
	struct _Item* next;
	struct _Item* prev;

}Item;

Item* Head;
Item* Tail;


void add(int val) {

	Item* move = (Item*)malloc(sizeof(Item));
	if (!move) return 1;

	move->next = NULL;
	move->val = val;

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

		printf("%d\n", print->val);
		print = print->next;

	}
}





void switchBetweenHeadAndTail(Item* toSwitch) {
	toSwitch->next = NULL;
	toSwitch->prev = Tail;
	Tail->next = Head;
	Tail->prev = NULL;
	Tail = toSwitch;
	Head = toSwitch->prev;
}

void switchBetweenHeadAndRegularItem(Item* toSwitch) {
	toSwitch->prev = toSwitch->next;
	toSwitch->prev->prev = NULL;
	toSwitch->next = toSwitch->next->next;
	toSwitch->next->prev = Head;
	toSwitch->prev->next = Head;
	Head = toSwitch->prev;
}

void switchBetweenRegularItemAndTail(Item* toSwitch) {

	Tail->prev = toSwitch->prev;
	Tail->next = toSwitch;
	toSwitch->next = NULL;
	toSwitch->prev = Tail;
	Tail->prev->next = Tail;
	Tail = toSwitch;

}

void switchBetweenToRegularItems(Item* toSwitch) {
	toSwitch->next->prev = toSwitch->prev;
	toSwitch->prev = toSwitch->next;
	toSwitch->next = toSwitch->next->next;
	toSwitch->next->prev = toSwitch;
	toSwitch->prev->prev->next = toSwitch->prev;
	toSwitch->prev->next = toSwitch;
}

void switchBetweenTwo(Item* toSwitch) {

	if (toSwitch == NULL) return NULL;
	else if (toSwitch == Head && toSwitch->next == NULL) return NULL;
	else if (toSwitch == Head && toSwitch->next == Tail) {

		switchBetweenHeadAndTail(toSwitch);
	}
	else if (toSwitch == Head) {

		switchBetweenHeadAndRegularItem(toSwitch);
	}
	else if (toSwitch->next == Tail) {

		switchBetweenRegularItemAndTail(toSwitch);
	}
	else {

		switchBetweenToRegularItems(toSwitch);
	}


}

void sortBetweenTwo() {
	Item* currentItem = Head;
	int notSorted = 1;

	while (notSorted != 0) {
		notSorted = 0;
		currentItem = Head;
		while (currentItem != NULL) {
			if (currentItem->next != NULL && currentItem->val > currentItem->next->val) {
				switchBetweenTwo(currentItem);
				notSorted = 1;
			}
			currentItem = currentItem->next;
		}
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


void ResetList() {
	if (!Head) {
		return;
	}
	freeItem();
	Head = NULL;
	Tail = NULL;
}


int main() {
    add(7);
    add(9);
	add(8);
	add(2);
	add(3);
	add(100);
	add(5);
	PrintList();
	printf("\n");
	sortBetweenTwo();
	PrintList();
    ResetList();
	return 0;
}