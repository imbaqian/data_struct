

#include "minheap.h"
#include <stdio.h>
int main()
{
	int i;
	MinHeap MH;
	MH = BuildMinHeap(30);
	InsertMinHeap(MH,6);
	printf("Delete:%d\n",DeleteMinHeap(MH));
	for(i=1;i<=MH->Size;i++)
		printf("%d ",MH->Data[i]);
}
