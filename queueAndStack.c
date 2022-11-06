//#include <stdio.h>
//#include <stdlib.h> 
//#include <string.h>
//#include <conio.h>
//#include <time.h>
//
//#pragma warning(disable:4996)
//
//
//typedef struct _Item {
//
//	int Val;
//	struct _Item* next;
//	struct _Item* prev;
//
//
//}Item;
//
//extern Item* Head = NULL;
//extern Item* Tail = NULL;
//
//
//
//
//Item* popQueue() {
//
//	Item* move = Head;
//	if (Head->next != NULL) {
//
//		Head = Head->next;
//		Head->prev = NULL;
//	}
//
//	return move;
//}
//
//
//Item* popStack() {
//	Item* move = Tail;
//	if (Tail->prev != NULL) {
//
//		Tail = Tail->prev;
//		Tail->next = NULL;
//	}
//	return move;
//}