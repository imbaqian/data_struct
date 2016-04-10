#include <stdio.h>
#include <malloc.h>
void Swap(int *a,int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void mySort(int A[],int N)/*做题偷懒写个冒泡*/
{
	int i,j;
	for(i=0;i<N;i++)
		for(j=i+1;j<N;j++){
			if(A[i] > A[j])
				Swap(&A[i],&A[j]);
		}
}
void Insert_Sort(int B[],int j)
{
	int i;
	for(i=j;i>=0;i--){
		if(B[i] < B[i-1])
			Swap(&B[i],&B[i-1]);
		else
			break;
	}
}
void Merge_Sort(int B[],int N)
{
	int i;
	int l;
	int p;
	int flag = 0;
	
	for(l = 2; l<=N; l*=2){
		p = l;
		while(p < N){
			if(B[p-1] > B[p]){
				flag = 1;
				break;
			}
			p = p + 2 * l;

		}
		if(flag)
			break;
	}
	
	l = l * 2;
	for(i = 0; i<N; i = i + l){
		if(i+l >= N)
			l = N-i;
		mySort(B+i,l);
	}


		
}

void SampleInput(int **A,int **B,int *N)/*这里用了二级指针。刚开始都迷糊了*/
{
	int i;
	scanf("%d",&i);
	*N = i;
	(*A) = (int *)malloc(i *sizeof(int));
	(*B )= (int *)malloc(i *sizeof(int));
	for(i = 0; i<*N; i++)
		scanf("%d",&(*A)[i]);
	for(i = 0; i<*N; i++)
		scanf("%d",&(*B)[i]);
}
void Insert_or_Merge(int A[],int B[],int N)
{
	int i;
	int j;
	int flag = 0;/*flag=0是插入排序，flag=1是归并排序*/
	for(i=1;i<N;i++){
		if(B[i] < B[i-1]){
			j = i;
			break;
		}
	}
	for(;i<N;i++){
		if(A[i] != B[i])
			flag = 1;
	}
	if(flag == 0){
		printf("Insertion Sort\n");
		Insert_Sort(B,j);
	}
	else{
		printf("Merge Sort\n");
		Merge_Sort(B,N);
	}
	printf("%d",B[0]);
	for(i=1;i<N;i++)
		printf(" %d",B[i]);
}


int main()
{
	int *A;
	int *B;
	int N;
	SampleInput(&A,&B,&N);
	Insert_or_Merge(A,B,N);
}
