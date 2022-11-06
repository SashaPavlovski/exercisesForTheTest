#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)



typedef struct _Leaf {

	int level;
	struct _Leaf* Right;
	struct _Leaf* Left;
	struct _Leaf* Parent;

	int val;

}Leaf;

Leaf* Root;

void addNewLeaf(Leaf* curr, int val) {
	Leaf* newLeaf = (Leaf*)malloc(sizeof(Leaf));
	if (!newLeaf) return 1;
	newLeaf->val = val;
	newLeaf->Right = NULL;
	newLeaf->Left = NULL;
	
	if (Root == NULL) {
		Root = newLeaf;
		newLeaf->Parent = NULL;
		newLeaf->level = 0;
	}
	else
	{
		if(curr == NULL){
			curr = Root;
		}
		if (curr->val < val) {

			if (curr->Right == NULL) {
				curr->Right = newLeaf;
				newLeaf->Parent = curr;
				newLeaf->level = curr->level + 1;
			}
			else {
				free(newLeaf);
				addNewLeaf(curr->Right, val);
			}
		}
		else {

			if (curr->Left == NULL) {
				curr->Left = newLeaf;
				newLeaf->Parent = curr;
				newLeaf->level = curr->level + 1;

			}
			else {
				free(newLeaf);
				addNewLeaf(curr->Left, val);
			}
		}
	}
}

void printTree(Leaf* Item) {

	if (!Item) return;

	printTree(Item->Left);
	printf("%d\n", Item->val);
	printTree(Item->Right);

}


int main() {

	Root = NULL;
    addNewLeaf(NULL, 3);
	addNewLeaf(NULL, 9);
	addNewLeaf(NULL, 4);
	addNewLeaf(NULL, 2);
	addNewLeaf(NULL, 223);
	addNewLeaf(NULL, 23);
	addNewLeaf(NULL, 5);
	addNewLeaf(NULL, 123);
	addNewLeaf(NULL, 322);
	addNewLeaf(NULL, 10);
	addNewLeaf(NULL, 100);
	printTree(Root);

	return;
}