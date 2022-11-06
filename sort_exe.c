#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>
#include <time.h>

#pragma warning(disable:4996)


typedef struct _Item {

	int Val;
	struct _Item* next;
	struct _Item* prev;


}Item;

extern Item* Head = NULL;
extern Item* Tail = NULL;
Item* curr;

void LocateBetweenItems(Item* theBiggest);
void LocateBeforTheHead();
Item* biggest(int val);
void PrintList();


void PrintList() {

	Item* print = Head;
	while (print != NULL) {

		printf("%d\n", print->Val);
		print = print->next;

	}
}

void ResetList() {
	if (!Head) {
		return;
	}
	Head = NULL;
	Tail = NULL;
}

Item* biggest(int val) {

	Item* current = Head;
	int bigger = val;
	while (current) {
		if (current->Val > bigger)return current;
		current = current->next;
	}
	return NULL;
}



void sort(int val) {

	curr = (Item*)malloc(sizeof(Item));
	if (!curr)return;
	curr->Val = val;

	if (Head == NULL) {

		Head = curr;
		Tail = curr;
		curr->prev = NULL;
		curr->next = NULL;
	}
	else {

		Item* theBiggest = biggest(val);
		if (theBiggest == NULL) {

			Tail->next = curr;
			curr->prev = Tail;
			curr->next = NULL;
			Tail = curr;
		}
		else if (theBiggest == Head) {

			LocateBeforTheHead();

		}
		else {

			LocateBetweenItems(theBiggest);

		}

	}


}

void LocateBetweenItems(Item* theBiggest) {

	curr->next = theBiggest;
	curr->prev = theBiggest->prev;
	theBiggest->prev = curr;
	curr->prev->next = curr;

}

void LocateBeforTheHead() {

	curr->prev = NULL;
	curr->next = Head;
	Head->prev = curr;
	Head = curr;

}


int main_12() {
	sort(7);
	sort(9);
	sort(8);
	sort(2);
	sort(3);
	sort(100);
	sort(5);
	
	PrintList();

	return;
}