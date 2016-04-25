#include "stack.h"
#include <malloc.h>
Stack CreateStack(int size)
{
	Stack newstack = (Stack)malloc(sizeof(struct NStack));
	newstack->s = (Item*)malloc(size * sizeof(Item));
	newstack->size = size;
	newstack->top = 0;
	return newstack;
}
int push(Item it,Stack s)
{
	if(s->top != (s->size - 1)){
		s->s[s->top] = it;
		s->top++;
		return 1;
	}
	else 
		return 0;
}

int pop(Item *it,Stack s)
{
	if(s->top == 0){
		return 0;
	}
	else{
		*it =  s->s[--s->top];
		return 1;
	}
}

