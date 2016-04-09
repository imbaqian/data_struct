/*基数排序
	---次位优先(Least Significant Digit)
 */
#include <malloc.h>
#include <stdio.h>
typedef int ElementType;

/*假设元素做多有MaxDigit个关键字，基数全是同样的Radix*/
#define MaxDigit 11	/*最高取到千位*/
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


/*---------------下面是只有正数的基数排序--------------------------------*/
/*基数排序，次位优先*/
void LSDRadixSort(ElementType A[],int N)
{
	int D, Di, i;
	Bucket B;
	PtrToNode tmp, p, List = NULL;
	
	/*1.初始化每个桶为空链表*/
	for(i = 0;i < Radix ;i++)
		B[i].head = B[i].tail = NULL;
	/*2.(头插)将原始序列逆序存入初始链表List*/
	for(i = 0;i < N;i++){
		tmp = (PtrToNode)malloc(sizeof(struct BucketNode));
		tmp->key = A[i];
		tmp->next = List;
		List = tmp;	
	}

	/*3.排序 ↓ 改了下面的for循环可以改成主位优先～从MaxDigit～1 */
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
	/*4.将List中的值放会A数组中*/
	for(i=0;i<N;i++){
		tmp = List;
		List = List->next;
		A[i] = tmp->key;
		free(tmp);
	}
}

/*---------------------------------------------------------------------------------*/


void lsd(int A[],int n)
{
	int i;
	int Di;
	int D;
	int negNum = 0;
	int posNum = 0;
	PtrToNode negPtr = NULL;/*负数表头*/
	PtrToNode posPtr = NULL;/*正数表头*/
	PtrToNode tmp;
	PtrToNode p;
	Bucket posBucket;/*正数桶*/
	Bucket negBucket;/*负数桶*/
	/*初始化每个桶为空～～～～*/
	for(i=0;i<Radix;i++){
		posBucket[i].head = posBucket[i].tail = NULL;
		negBucket[i].head = negBucket[i].tail = NULL;
	}

	/*把正负数分开放在链表中*/
	for(i=0;i<n;i++){
		tmp = (PtrToNode)malloc(sizeof(struct BucketNode));
		tmp->key = A[i];
		if(A[i] < 0 ){
			negNum++;
			tmp->next = negPtr;
			negPtr = tmp;
		}
		else{
			posNum++;
			tmp->next = posPtr;
			posPtr = tmp;
		}
	}
	/*分开在桶中*/
	for(Di=1;Di<=MaxDigit;Di++){
		p = posPtr;
		while(p){

			
			tmp = p;
			p = p->next;
			tmp->next = NULL;
			D = GetDigit(tmp->key,Di); /*获得桶号*/
			if(posBucket[D].head == NULL)
				posBucket[D].head = posBucket[D].tail = tmp;
			else{
				posBucket[D].tail->next = tmp;
				posBucket[D].tail = tmp;
			}				
		}
		/*收集正数到正数链表posPtr   9~1*/
		posPtr = NULL;
		for(D = Radix - 1; D >= 0; D--){/*正数*/
			if(posBucket[D].head != NULL){
				posBucket[D].tail->next = posPtr;
				posPtr = posBucket[D].head;
				posBucket[D].head = posBucket[D].tail = NULL; /* 清空桶 */
			}	
		}	
	}

	/*分配负数在桶中*/
	for(Di=1;Di<=MaxDigit;Di++){
		p = negPtr;
		while(p != NULL){
			tmp = p;
			p = p->next;
			tmp->next = NULL;
			D = GetDigit(-(tmp->key),Di);
			if(negBucket[D].head == NULL)
				negBucket[D].head = negBucket[D].tail = tmp;
			else{
				negBucket[D].tail->next = tmp;
				negBucket[D].tail = tmp;
			}
		}
		/*收集负数到负数链表negPtr,顺序是从小到大*/
		negPtr = NULL;
		for(D =Radix-1 ;D>=0; D--){/*负数*/
			if(negBucket[D].head != NULL){
				negBucket[D].tail->next = negPtr;
				negPtr = negBucket[D].head;
				negBucket[D].head = negBucket[D].tail = NULL; /* 清空桶 */
				}	
			}
		}	
	
	



	i = 0;
	while(negPtr != NULL){
		tmp = negPtr;
		A[negNum-i-1] = tmp->key;
		i++;
		negPtr = negPtr->next;
		free(tmp);
	}

	while(posPtr != NULL){
		tmp = posPtr;
		A[i++] = tmp->key;
		
		posPtr = posPtr->next;
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
	
	//ElementType A[10] = {4 ,981 ,10 ,-17, 0, -20, 29, 50,  43, -5};
	//ElementType  A[5] = {4,33,22,11,3 };
	n =10;
	lsd(A,n);
	
	//LSDRadixSort(A,n);
	printf("%d",A[0]);
	for(i=1;i<n;i++){
		printf(" %d",A[i]);
	}
	free(A);
}
