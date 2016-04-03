#include <stdio.h>
#include <malloc.h>


typedef int ElementType;
/*-----------递归实现归并排序------------------------*/
/*L = 左边起始位置.R = 右边起始位置，RightEnd = 右边终点位置*/
void Merge(ElementType A[],ElementType TmpA[],int L,int R,int RightEnd)
{/*将有序的A[L]~A[R-1] 和 A[R]~A[RightEnd] 归并为一个有序序列*/
	int LeftEnd , NumElementS,Tmp;
	int i;
	LeftEnd = R - 1; /*左边终点位置*/
	Tmp = L;/*有序序列起始位置*/
	NumElementS = RightEnd - L + 1;/*有序序列元素个数*/
	while(L <= LeftEnd && R <= RightEnd){ /*将两左右合并到TmpA[]*/
		if(A[L] <= A[R])
			TmpA[Tmp++] = A[L++];
		else
			TmpA[Tmp++] = A[R++];
	}
	while(L <= LeftEnd) /*将剩下的直接拷贝到TmpA[]*/
		TmpA[Tmp++] = A[L++];
	while(R <= RightEnd)
		TmpA[Tmp++] = A[R++];
	/*递归需要下面两行，非递归不需要*/
	for(i=0;i<NumElementS;i++,RightEnd--)
		A[RightEnd] = TmpA[RightEnd];/*将有序的TmpA[]复制回A[]*/
}	

void MSort(ElementType A[],ElementType TmpA[],int L,int RightEnd)
{/*核心递归排序函数*/
	int center;
	if(L < RightEnd){
		center = (L + RightEnd)/2;
		MSort(A,TmpA,L,center); /*递归解决左边*/
		MSort(A,TmpA,center+1,RightEnd);/*递归解决右边*/
		Merge(A,TmpA,L,center+1,RightEnd);/*合并俩段有序序列*/
	}
}

void Merge_Sort(ElementType A[],int N)
{/*归并排序写成统一接口哦*/
	ElementType *TmpA;
	TmpA = (ElementType*)malloc(N*sizeof(ElementType));
	if(TmpA != NULL){
		MSort(A,TmpA,0,N-1);
		free(TmpA);
	}
	else
		printf("空间不足");
}

/*---------------------非递归实现------------------------------*/

void Merge_pass(ElementType A[],ElementType TmpA[],int N,int length)
{/*俩俩归并相邻子序列,A[]→ TmpA[]
  */
	int i,j;
	for(i=0;i<=N-2*length;i+=2*length)/*归并倒数前2的子列*/
		Merge(A,TmpA,i,i+length,i+2*length-1);
	if(i+length < N) /*归并最后2个子列*/
		Merge(A,TmpA,i,i+length,N-1);
	else /*只剩最后1个子列*/
		for(j=i;j<N;j++)
			TmpA[j] = A[j];
}

void Merge_Sort1(ElementType A[],int N)
{/*统一接口的哦～*/
	int length;
	ElementType *TmpA;
	length = 1;
	TmpA = (ElementType*)malloc(N*sizeof(ElementType));
	if(TmpA != NULL){
		while(length < N){
			Merge_pass(A,TmpA,N,length);
			length *= 2;
		//	Merge_pass(TmpA,A,N,length);
		//	length *= 2;
		}
		free(TmpA);
	}
	else
		printf("空间不足");
}

int main()
{
	int i;
	ElementType A[10] = {6,8,7,9,5,4,3,2,1,0};
	Merge_Sort1(A,10);
	for(i=0;i<10;i++)
	{
		printf("%d ",A[i]);
	}

}
