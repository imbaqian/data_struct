#include <stdio.h>
typedef int ElementType; 
void Swap(ElementType *a,ElementType *b)
{
	ElementType t = *a;
	*a=*b;
	*b =t;
}

/*将N个元素的数组中以A[p]为根的子堆调整成最大堆*/
void PercDown(ElementType A[],int p,int N)
{
	int parent,child;
	ElementType x;
	x = A[p];/*取出根结点存放的值*/
	for(parent=p;(parent*2+1)<N;parent = child){
		child = parent * 2 + 1;
		if( (child != N-1) && (A[child]<A[child+1]))
			child++;
		if(x > A[child])
			break;
		else/*下滤*/
			A[parent] = A[child];
	}
	A[parent] = x;
}
/*堆排
	给的数据和以前的最小堆有所不同，
	这次是A[0]中没有哨兵
	所以父亲结点与左儿子结点的关系是 child = parent*2 + 1 
	
 */
void Heap_Sort(ElementType A[],int N)
{
	int i;
	/*？？？？？？这里为什么i=N/2-1也是对的呢？？？？？？？？？*/
	for(i=(N-1)/2;i>=0;i--)/*调整为最大堆*/
		PercDown(A,i,N);
	for(i=N-1;i>0;i--){
		Swap(A,A+i); /*A[0](最大值) 与A[i](最小值)*/
		PercDown(A,0,i);/*将A[0]为根，有i个元素的的堆，调为最大堆，*/
	}
}

int main()
{
	int i;
	ElementType a[10] = {10,9,8,7,6,5,4,3,2,1};
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	Heap_Sort(a,10);
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	printf("%d",5/2-1);
	return 0;
} 
