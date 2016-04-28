#include "avl.h"
#include <stdio.h>
#include <malloc.h>

int Max(int a,int b)
{
	return a > b ? a : b;
}
AVLTree singleLeftRotation(AVLTree A)
{
	AVLTree B;
	B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left),GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left),GetHeight(B->Right)) + 1;
	return B;
}
AVLTree singleRightRotation(AVLTree A)
{
	AVLTree B;
	B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left),GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left),GetHeight(B->Right)) + 1;
	return B;
}
AVLTree doubleLeftRightRotation(AVLTree A)
{
	A->Right = singleRightRotation(A->Right);
	return singleLeftRotation(A);	
}
AVLTree doubleRightLeftRotation(AVLTree A)
{
	A->Left = singleLeftRotation(A->Left);
	return singleRightRotation(A);

}
AVLTree Insert(AVLTree T, ElementType X)
{/*将X插入AVL树T中，并且返回调整后的AVL树*/
	if(T == NULL){ /*如果插入数为空，则新建包含一个结点的树*/
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Height = 0;
		T->Data = X;
		T->Left = T->Right = NULL;
	}
	else if(X < T->Data){ /*插入左子树*/
		T->Left = Insert(T->Left,X);
		if(GetHeight(T->Left) - GetHeight(T->Right) == 2){/*如果需要左旋*/
			if(X < T->Left->Data) /*插入的是左子树的左子树，则左单旋*/
				T = singleLeftRotation(T);
			else/*插入的是左子树的右子树，则左右旋*/
				T = doubleLeftRightRotation(T);
		}
	}
	else if(X > T->Data){ /*插入右子树*/
		T->Right = Insert(T->Right,X);
		if(GetHeight(T->Left) - GetHeight(T->Right) == -2){/*如果需要右旋*/
			if(X > T->Right->Data)/*插入的是右子树的右子树，右单旋*/
				T = singleRightRotation(T);
			else/*插入的是右子树的左子树,则右左旋*/
				T = doubleRightLeftRotation(T);
		}
	}
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	return T;
}
int GetHeight(AVLTree T)
{
	if(T == NULL)
		return 0;
	else
		return T->Height;

}

void PreOrderTraversal(AVLTree AVL)
{
	if(AVL != NULL){
		printf("%d ",AVL->Data);
		PreOrderTraversal(AVL->Left);
		PreOrderTraversal(AVL->Right);
	}
}
