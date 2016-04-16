#include <stdio.h>
#include <malloc.h>

typedef struct TNode{
	char data;
	struct TNode* LChild;
	struct TNode* RChild;
}*BinTree;

void CreateBinTree(BinTree* bt)
{
	char ch;
	ch = getchar();
	if(ch == '#'){
		*bt = NULL;
	}
	else{
		*bt = (BinTree)malloc(sizeof(struct TNode));
		(*bt)->data = ch;
		CreateBinTree(&((*bt)->LChild));
		CreateBinTree(&((*bt)->RChild));
	}
}

void PreOrder(BinTree bt)
{
	if(bt != NULL){
		printf("%c ",bt->data);
		PreOrder(bt->LChild);
		PreOrder(bt->RChild);
	}
}
int main(void)
{
	BinTree bt;
	CreateBinTree(&bt);
	PreOrder(bt);
}

