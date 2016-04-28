/*
    二叉树--功能实现
*/
#include "bintree.h"
#include <stdio.h>
#include <malloc.h>
/*递归查找*/
Position Find(ElementType X, BinTree BST)
{
	if(BST == NULL )
		return NULL;
	if(X > BST->Data)
		return Find(X,BST->Right);
	else if(X < BST->Data)
		return Find(X, BST->Left);
	else /*X == BST->Data*/
		return BST;
}
/*非递归的查找*/
Position IterFind(ElementType X, BinTree BST){
	while(BST != NULL){
		if(X > BST->Data)
			BST = BST->Right;
		else if(X < BST->Data)
			BST = BST->Left;
		else /* BST->Data == X */
			return BST;
	}
	return NULL;/*没找到*/
}
Position FindMin(BinTree BST)
{
	if(BST != NULL)
		while(BST->Left != NULL)
			BST = BST->Left;
	return BST;
}
Position FindMax(BinTree BST)
{
	if(BST != NULL)
		while(BST->Right != NULL)
			BST = BST->Right;
	return BST;
}
/*递归插入*/
BinTree Insert(ElementType X, BinTree BST)
{
	if(BST == NULL){
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Left = NULL;
		BST->Right = NULL;
		BST->Data = X;
	}
	else{ 
		if(X < BST->Data)
			BST->Left = Insert(X,BST->Left);
		else
			BST->Right = Insert(X,BST->Right);
	}
	return BST;
}


/*
	删除的方法：
	1.p 为叶子结点，直接删除，并将其父结点指向他的指针置为NULL
	2.p 只有一个儿子，将父结点指针指向要删除孩子的下一个孩子
	3.p 有2个儿子，用另以结点代替被删除结点：右子树的最小值或者左子树的最大值。

 */
BinTree Delete(ElementType X, BinTree BST)
{
	Position tmp;
	if(BST == NULL)
		printf("can't find %d\n",X);
	else{
		if(X < BST->Data)
			BST->Left = Delete(X,BST->Left);/*左子树递归删除*/
		else if(X > BST->Data)
			BST->Right = Delete(X,BST->Right);/*右子树递归删除*/
		else if(X == BST->Data){/* BST 就是要删除的结点 */
			if(BST->Left && BST->Right){/*如果要删除的结点有左右儿子*/
				tmp = FindMin(BST->Right);/*找到右儿子中最小的儿子，放到当前位置*/
				BST->Data = tmp->Data;
				BST->Right = Delete(BST->Data,BST->Right);/*从右子树中删除最小元素*/
			}
			else{
				tmp = BST;
				if(BST->Left == NULL)/*只有右子树*/
					BST = BST->Right;
				else if(BST->Right == NULL)/*只有左子树*/
					BST = BST->Left;
				free(tmp);
			}
		}
	}
	return BST;
}
void InOrderTraversal(const BinTree BST){
	if( NULL != BST){
		InOrderTraversal(BST->Left);
		printf("%d ",BST->Data);
		InOrderTraversal(BST->Right);
	}
}
