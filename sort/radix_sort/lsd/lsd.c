/*基数排序
	---次位优先(Least Significant Digit)
 */
#include <malloc.h>
#include <stdio.h>
typedef int ElementType;

/*假设元素做多有MaxDigit个关键字，基数全是同样的Radix*/
#define MaxDigit 4	/*最高取到千位*/
#define Radix 10	/*十个桶，0,1,2,3,4,5,6,7,8,9*/


/*桶元素结点*/

typedef struct BucketNode* PtrToNode;

struct BucketNode{
	int key;
	PtrToNode next;
};

/*桶头结点*/
struct HeadNode{
	PtrToNode head,tail;	
};
typedef struct HeadNode Bucket[Radix];


/*取个十百千万，D=1取个位，D=2取十位，D=3取百位..并且返回该位*/
int GetDigit(int x,int D)
{
	int d,i;
	for(i=1;i<=D;i++){
		d = x % Radix;
		x /= Radix;
	}
	return d;
}

/*基数排序，次位优先*/
void LSDRadixSort(ElementType A[],int N)
{
	int D, Di, i;
	Bucket B;
	PtrToNode tmp, p, List = NULL;
	for(i = 0;i < Radix ;i++)/*初始化每个桶为空链表*/
		B[i].head = B[i].tail = NULL;
	for(i = 0;i < N;i++){/*(头插)将原始序列逆序存入初始链表List*/
		tmp = (PtrToNode)malloc(sizeof(struct BucketNode));
		tmp->key = A[i];
		tmp->next = List;
		List = tmp;	
	}

	/*排序 ↓ 改了下面的for循环可以改成主位优先～从MaxDigit～1 */
	for(D=1;D<=MaxDigit;D++){
		/*下面是分配的过程*/
		p = List;
		while(p){
			Di = GetDigit(p->key,D);/*找到Di号桶*/
			/*从List中摘除*/
			tmp = p;
			p = p->next;
			/*插入B[Di]号桶尾*/
			tmp->next = NULL;
			if(B[Di].head == NULL)
				B[Di].head = B[Di].tail = tmp;
			else{/*尾插*/
				B[Di].tail->next = tmp;
				B[Di].tail = tmp;
			}
		}
		/*收集过程，方法多样，插进List就可以了*/
		List = NULL;
		for(Di = Radix-1;Di>=0;Di--){/*这里用的方法:将9~0号桶依次头插进List*/
			if(B[Di].head){
				B[Di].tail->next = List;
				List = B[Di].head;
				B[Di].head = B[Di].tail = NULL;
			}
		}
	}
	/*将List中的值放会A数组中*/
	for(i=0;i<N;i++){
		tmp = List;
		List = List->next;
		A[i] = tmp->key;
		free(tmp);
	}
}
int main()
{
	int n;
	int i;
	ElementType* A;
	scanf("%d",&n);
	A = (ElementType*)malloc(n*sizeof(ElementType));
	for(i=0;i<n;i++){
		scanf("%d ",A+i);
	}
	LSDRadixSort(A,n);
	printf("%d",A[0]);
	for(i=1;i<n;i++){
		printf(" %d",A[i]);
	}
}
