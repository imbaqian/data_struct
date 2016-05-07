#include <stdio.h>
typedef int ElementType;
void Swap(ElementType* a,ElementType* b)
{
	ElementType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void Quick_Sort(ElementType A[],int Left,int Right)
{
	ElementType pivot;
	int low,high;
	pivot = A[Left];
	low = Left+1;
	high = Right;

	if(Left < Right){
		while(1){
			while(A[low] < pivot)
				low++;
			while(A[high] > pivot)
				high--;
			if(low < high)
				Swap(&A[low],&A[high]);
			else
				break;
		}		
		Swap(&A[Left],&A[high]);
		Quick_Sort(A,Left,high-1);
		Quick_Sort(A,high+1,Right);
	}
}



int main()
{
	int i;
	ElementType A[] = {1,3,2,4};
	int size = sizeof(A) / sizeof(ElementType);
	Quick_Sort(A,0,size-1);
	for(i=0;i<size;i++){
		printf("%d ",A[i]);
	}

	return 0;

}
