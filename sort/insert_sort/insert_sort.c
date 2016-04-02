#include <stdio.h>
typedef int ElementType;
/*插入排序*/
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
} int main()
{
	int i;
	ElementType a[10] = {2,33,22,55,44,11,0,2,3,5};
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	Insert_Sort(a,10);
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}


