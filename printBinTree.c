#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)




void printTree(TLeaf* leaf)
{
	if (leaf == NULL) {
		return;
	}

	printTree(leaf->Left);

	printf("%d\n", leaf->Val);

	printTree(leaf->Right);
}
