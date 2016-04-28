#include "avl.h"
#include <stdio.h>


int main(void)
{
	AVLTree avl = NULL;
	avl = Insert(avl,1);
	avl = Insert(avl,2);
	avl = Insert(avl,3);
	avl = Insert(avl,4);
	avl = Insert(avl,5);
	avl = Insert(avl,6);
	PreOrderTraversal(avl);
	return 0;
}
