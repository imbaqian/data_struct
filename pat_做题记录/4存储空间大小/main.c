#include <iostream>
#include <stdio.h>
#include <malloc.h>
#pragma pack(2)

class BU
{
	int number;//4
	union UBffer//14
	{
		char buffer[13];
		int number;
	}ubuf;
	void foo(){}
	char* (*f)(void*);//4
	enum{hdd,ssd,blueray}disk;//4
}bu;


int main()
{
    int *a;	
    printf("%ld\n",sizeof(a));
    char *b = (char *)malloc(2);
    printf("%d",*(b-1));
    return 0;
}