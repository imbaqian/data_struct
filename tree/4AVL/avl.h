/*
	平衡二叉树的建立
 */
typedef int ElementType;
typedef struct AVLNode *Position;
typedef Position AVLTree;
struct AVLNode{
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};
int Max(int a,int b);
AVLTree singleLeftRotation(AVLTree A);
AVLTree singleRightRotation(AVLTree A);
AVLTree doubleLeftRightRotation(AVLTree A);
AVLTree doubleRightLeftRotation(AVLTree A);
AVLTree Insert(AVLTree T, ElementType X);
int GetHeight(AVLTree T);

void PreOrderTraversal(AVLTree AVL);
