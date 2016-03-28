#ifndef MINHEAP_H_
#define MINHEAP_H_




typedef int ElementType;
typedef struct HNode* Heap;
struct HNode{
	ElementType* Data; /*存储元素的数组*/
	int Size;		/*堆中当前元素个数*/
	int Capacity;	/*堆的最大容量*/
};

typedef Heap MaxHeap;
typedef Heap MinHeap;

#define MAXDATA 1000
#define MINDATA -1
/*创建容量为MaxSize的空的最小堆*/
MinHeap CreateMinHeap( int MaxSize );

int IsFull(MinHeap H);

int InsertMinHeap(MinHeap H,ElementType x);
ElementType DeleteMinHeap(MinHeap H);
/*------------堆操作 ↑-------------------------*/
/*------------建造最小堆 ↓--------------------*/

/*下滤：将H中以H->Data[p]为根的子堆调为最小堆*/
void PerDown(MinHeap H,int p);
void BuildHeap(MinHeap H);

#endif
