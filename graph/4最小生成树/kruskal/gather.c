#include "gather.h"

void SetUnion(SetType S[],ElementType X1,ElementType X2)
{
	int Root1,Root2;
	Root1 = SetFind(S,X1);
	Root2 = SetFind(S,X2);
	if(Root1 != Root2){
		if(S[Root1].parent < S[Root2].parent ){/*集合1 > 集合2*/ 
			S[Root1].parent += S[Root2].parent;
			S[Root2].parent = Root1;
		}
		else{
			S[Root2].parent += S[Root1].parent;
			S[Root1].parent = Root2;	
		}
	}
}

SetName SetFind(SetType S[],ElementType X)
{
	int i;
	for(i=0;i<MAXN;i++){
		if(S[i].Data == X)
			break;
	}
	if(S[i].parent < 0)
		return i;
	else
		return S[i].parent = SetFind(S,S[S[i].parent].Data);
}
