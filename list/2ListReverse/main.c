#include <stdio.h>
#include <malloc.h>
typedef struct LNode{
	int data;
	struct LNode* Next;
}*List;
List Reverse( List L )
{
    List Old_head, New_head, Temp;
    New_head = NULL;
    Old_head = L->Next;
    while ( Old_head )  {	/*就是头插*/
        Temp = Old_head->Next;
        Old_head->Next = New_head;
        New_head = Old_head;  
        Old_head = Temp; 
    }
    L->Next = New_head;
    return L;
}

int main(void)
{
	List L;
	List tmp;
	L = (List)malloc(sizeof(struct LNode));
	L->data = -1;
	L->Next = (List)malloc(sizeof(struct LNode));
	L->Next->data = 2;
	L->Next->Next = (List)malloc(sizeof(struct LNode));
	L->Next->Next->data = 3;
	L->Next->Next->Next = (List)malloc(sizeof(struct LNode));
	L->Next->Next->Next->data = 4;
	L->Next->Next->Next->Next = NULL;
	L = Reverse(L);
	tmp = L->Next;
	while(tmp)
	{
		printf("%d ",tmp->data);
		tmp=tmp->Next;
	}
}