/*
    二叉搜索树--ooo
*/

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

Position Find(ElementType X, BinTree BST);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);
BinTree Insert(ElementType X, BinTree BST);
BinTree Delete(ElementType X, BinTree BST);
void InOrderTraversal(const BinTree BST);
