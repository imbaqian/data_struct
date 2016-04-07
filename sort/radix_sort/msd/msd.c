/*基数排序-主位优先*/
/*将设元素最多有MaxDigit个关键字，基数全是同样的Radix*/
#include <stdio.h>
#include <malloc.h>
typedef int ElementType;

#define MaxDigit 4
#define Radix 10

typedef struct BucketNode* PtroToNode;
/*桶元素结点*/
struct BucketNode{
	int key;
	PtroToNode next;
};
/*桶头结点*/
struct HeadNode{
	PtroToNode head,tail;
};

typedef struct HeadNode Bucket[Radix];

int GetDigit(int X,int D)
{
	int d,i;
	for(i=1;i<=D;i++){
		d = X % Radix;
		X /= Radix;
	}
	return d;
}
/*递归函数，对A[L]~A[R]的第D位数排序*/
void MSD(ElementType A[],int L,int R,int D)
{
	int Di,i,j;
	Bucket B;
	PtroToNode tmp, p, List = NULL;
	
	if(D == 0)/*递归终止条件*/
		return;
	
	/*初始化每个桶为空*/
	for(i=0; i<Radix; i++){
		B[i].head = B[i].tail = NULL;
	}
	
	/*将原始序列逆序存入初始化链表List*/
	for(i=L;i<=R;i++){
		tmp = (PtroToNode)malloc(sizeof(struct BucketNode));
		tmp->key = A[i];
		tmp->next = List;
		List = tmp;
	}

	/*下面是分配的过程，根据Di将每个数分到各个桶里*/
	p = List;
	while(p){
		Di = GetDigit(p->key,D);
		tmp = p;
		p = p->next;
		if(B[Di].head == NULL)/*桶为空的插法*/
			B[Di].tail = tmp;
		tmp->next = B[Di].head;
		B[Di].head = tmp;
	}

	i = j = L;/*i,j记录当前要处理的A[]的左右下标*/

	for(Di=0; Di<Radix; Di++){
		if(B[Di].head){
			p = B[Di].head;
			while(p){
				tmp = p;
				p = p->next;
				A[j++] = tmp->key;
				free(tmp);
			}
			/*递归堆该桶数据排序，位数减一*/
			MSD(A,i,j-1,D-1);/*依次对各个桶进行排序*/
			i = j;/*为下一个桶对应的A[]左端*/
		}
	}
}


void MSDRadixSort(ElementType A[],int N)
{
	MSD(A,0,N-1,MaxDigit);
}

int main()
{
	ElementType A[10] = {9,8,7,6,5,4,3,2,1,0};
	MSDRadixSort(A,10);
}
