/*快排*/
#include <stdio.h>
typedef int ElementType;
void Swap(ElementType* a,ElementType* b)
{
	ElementType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/*取主元 ,采用左中右取中间值的方法*/
ElementType Median3(ElementType A[],int Left,int Right)
{
	int center = (Left + Right)/2;
	if(A[Left] > A[center])
		Swap(A+Left,A+center);
	if(A[Left] > A[Right])
		Swap(A+Left,A+Right);
	if(A[center] > A[Right])
		Swap(A+center,A+Right);
	/*此时A[Left] <= A[center] <= A[Right]*/
	Swap(A+center,A+Right-1);/*将基准Pivot藏到右边,因为A[Left]和A[Right]已经排好了*/
	/*只需要考虑A[Left+1]~A[Right-2]*/
	return A[Right-1];/*返回基准Pivot*/
}

void Insert_Sort(ElementType A[],int N)
{
	int i,j;
	ElementType temp;
	for(i=1;i<N;i++){
		temp  = A[i]; /*取出未排序序列中的第一个元素*/
		for(j=i; j>0 && A[j-1]>temp ;j--)
			A[j] = A[j-1];/*依次与已排序序列中元素比较并右移*/
		A[j] = temp;/*放进合适位置*/
	}
}



void QSort(ElementType A[],int Left,int Right)
{/*核心递归函数*/
	int pivot,cutoff,low,high;
	cutoff = 2;
	if(cutoff <= Right-Left){
		pivot = Median3(A,Left,Right);
		low = Left ;
		high = Right - 1;
		while(1){
			while(A[++low] < pivot);/*大于pivot就退出*/
			while(A[--high] > pivot);/*小于pivot就退出*/
			if(low < high)
				Swap(A+low,A+high);
			else
				break;
		}
		Swap(A+low,A+Right-1);
		QSort(A,Left,low-1);
		QSort(A,low+1,Right);
	}
	else/*Insert_Sort(ElementType A[],int N)*/
		Insert_Sort(A+Left,Right-Left+1);		
}
void Quick_Sort(ElementType A[],int N)
{/*接口统一哦*/
	QSort(A,0,N-1);
}
int main()
{
	int i;
	ElementType A[10] = {3,2,1,4};
	Quick_Sort(A,4);
	for(i=0;i<4;i++){
		printf("%d ",A[i]);
	}
}
