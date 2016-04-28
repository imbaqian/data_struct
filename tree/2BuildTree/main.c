#include <stdio.h>

#include "bintree.h"
int main(void)
{
	
	BinTree bt = NULL;
	bt = Insert(3,bt);
	bt = Insert(4,bt);
	bt = Insert(2,bt);
	bt = Insert(7,bt);
	bt = Insert(6,bt);
	bt = Insert(74,bt);
	bt = Insert(33,bt);
	bt = Insert(55,bt);
	InOrderTraversal(bt);
	printf("\n");
	bt = Delete(33,bt);
	bt = Delete(2,bt);
	bt = Delete(100,bt);

	InOrderTraversal(bt);
	return 0;
}

