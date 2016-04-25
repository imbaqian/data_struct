/*
   栈--c语言版
 */

#ifndef STACK_H_
#define STACK_H_

typedef int Item;
typedef struct NStack* Stack;
struct NStack{
	Item *s;
	int top;
	int size;
};

Stack CreateStack(int size);
int push(Item it,Stack s);
int pop(Item * it,Stack s);



#endif
