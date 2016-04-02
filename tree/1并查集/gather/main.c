#include <stdio.h>
#include "gather.h"

int main()
{
	int i;
	SetType S[20];
	for(i=0;i<20;i++){
		S[i].parent = -1;
		S[i].Data = i+1;
	}
	SetUnion(S,1,2);
	SetUnion(S,3,4);
	SetUnion(S,5,4);
	SetUnion(S,6,3);

	printf("5属于%d\n",SetFind(S,5));
	
	return 0;
}
