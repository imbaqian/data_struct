#include "gather.h"

void Union(SetType S[],ElementType X1,ElementType X2)
{
	int Root1,Root2;
	Root1 = SetFind(S,X1);
	Root2 = SetFind(S,X2);
	if(Root1 != Root2){
		if( (-S[Root1].parent) > (-S[Root2].parent) )
			S[Root2].parent = Root1;
		else
			S[Root1].parent = Root2;
	}
}

SetName SetFind(SetType S[],ElementType X)
{
	int i;
	for(i=0;i<MAXN;i++){
		if(S[i].Data == X)
			break;
	}
	if(i >= MAXN)
		return -1; /*未找到，返回-1*/
   for(;S[i].parent >=0 ; i = S[i].parent);	
   return i;
}
