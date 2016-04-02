#include <stdio.h>

typedef int ElementType;
void Bubble_Sort(ElementType A[],int N)
{
	int i,j;
	ElementType temp;
	for(i=N-1;i>=0;i--){
		for(j=0;j<i;j++){
			if(A[j] > A[j+1]){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}
int main()
{
	int i;
	ElementType a[10] = {2,33,22,55,44,11,0,2,3,5};
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	Bubble_Sort(a,10);
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
