#include "minheap.h"
#include <malloc.h>

MinHeap CreateMinHeap( int MaxSize )
{
	MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType*)malloc( (MaxSize + 1)* sizeof(ElementType));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Data[0] = MINDATA; /*定义哨兵为堆中所愿元素可能最小值*/
	return H;
}

int IsFull(MinHeap H)
{
	if(H->Size == H->Capacity)
		return 1;
	else return 0;
}

int InsertMinHeap(MinHeap H,ElementType x)
{

}

ElementType DeleteMinHeap(MinHeap H)
{
}

void PerDown(MinHeap H,int p)
{
}
void BuildMinHeap(MinHeap H)
{
}
