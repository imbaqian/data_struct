#include <stdio.h>
#include "stack.h"
void AddQueue(Item it, Stack s1, Stack s2)
{
	push(it,s1);
}
void DeleteQueue(Item* it, Stack s1, Stack s2)
{
	Item temp;
	if(s2->top != 0){
		pop(it,s2);
	}
	else
	{
		while(s1->top != 0){
			pop(&temp,s1);
			push(temp,s2);
		}
		pop(it,s2);
	}
	return;
}
int main(void)
{
	Stack s1;
	Stack s2;
	s1 = CreateStack(10);
	s2 = CreateStack(10);
	Item it = 1;
	AddQueue(it, s1,s2);
	it = 2;
	AddQueue(it,s1,s2);
	it = 3;
	AddQueue(it,s1,s2);
	DeleteQueue(&it,s1,s2);
	printf("%d\n",it);
	DeleteQueue(&it,s1,s2);
	printf("%d\n",it);
	DeleteQueue(&it,s1,s2);
	printf("%d\n",it);
}

