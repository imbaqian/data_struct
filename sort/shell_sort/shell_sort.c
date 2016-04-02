#include <stdio.h>
typedef int ElementType;
/*希尔排序，用sdegewick增量序列*/
void Shell_Sort(ElementType A[],int N)
{
	int Si,D,P,i;
	ElementType Tmp;
	int SedgeWick[] = {929,505,209,109,41,19,5,1,0};
	for(Si=0;SedgeWick[Si]>=N;Si++);/*初始的增量不能超过待排序列长度*/
	for(D=SedgeWick[Si];D>0;D=SedgeWick[++Si])
		for(P=D;P<N;P++){
			Tmp = A[P];
			for(i=P;i>=D && A[i-D]>Tmp;i-=D)
				A[i] = A[i-D];
			A[i] = Tmp;
		}	
}
int main()
{
	int i;
	ElementType a[10] = {2,33,22,55,44,11,0,2,3,5};
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	Shell_Sort(a,10);
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
