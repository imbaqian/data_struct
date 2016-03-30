#include "minheap.h"
#include <malloc.h>

MinHeap CreateMinHeap( int MaxSize )
{
	MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType*)malloc( (MaxSize + 1)* sizeof(ElementType));
	H->Size = 0;				/*0号位置存哨兵哦*/
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
/*最小堆的插入*/
int InsertMinHeap(MinHeap H,ElementType x)
{
	int child,parent;
	ElementType temp;
	if(H->Size == H->Capacity){
		printf("heap is full!\n");
		return 0;
	}
	H->Size++;
	H->Data[H->Size] = x;
	child = H->Size;
	for(;H->Data[child] < H->Data[child/2];child = parent){
		parent = child/2;
		temp = H->Data[parent];
		H->Data[parent] = H->Data[child];
		H->Data[child] = temp;
	}
	return 1;
}

ElementType DeleteMinHeap(MinHeap H)
{
	int child,parent;
	ElementType minElem,temp;
	
	if( 0 == H->Size){
		printf("heap is empty!");
		return 0;
	}
	minElem = H->Data[1];
	temp = H->Data[H->Size--];
	for(parent = 1; parent*2 <= H->Size ;parent = child){
		child = parent * 2;
		if(child < H->Size)
			if(H->Data[child] > H->Data[child + 1])
				child++;
		if(H->Data[child] < temp)
			H->Data[parent] = H->Data[child]; 
		else
			break;
	}
	H->Data[parent] = temp;
	return minElem;
}

/*下滤，将H中，以H->Data[p]为根的子堆调整为最大堆*/
void PerDown(MinHeap H,int p)/*和删除操作类似*/
{
	int child;
	int parent;
	ElementType temp;
	temp = H->Data[p];/*记录父亲结点*/
	for(parent = p;parent*2 <= H->Size;parent = child){
		child = parent * 2;
		if(child != H->Size)
			if(H->Data[child] > H->Data[child + 1])/*找出儿子中的较小值*/
				child++;
		
		if( temp > H->Data[child])/*如果父亲小于大于儿子，就让小儿子上来*/
			H->Data[parent] = H->Data[child];
	}
	H->Data[child] = temp;
}

/*调整H，使之成为最小堆*/
MinHeap BuildMinHeap(int MaxSize)
{
	int i;
	MinHeap mh;
	int dataNum;
	int data;
	mh = CreateMinHeap(MaxSize);
	printf("输入数据个数:");
	scanf("%d",&dataNum);
	
	for(i=1;i <= dataNum;i++){
		scanf("%d",&data);
		mh->Size++;
		mh->Data[i] = data;
		
	}
	for(i=mh->Size/2; i>0 ; i--){
		PerDown(mh,i);
	}
	return mh;
}
