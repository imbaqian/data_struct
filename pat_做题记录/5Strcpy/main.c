#include <stdio.h>
#include <assert.h>

char* myStrcpy(char *dest,const char *src)
{
    assert(dest != NULL && src != NULL);
    char * address = dest;
    while((*dest++ = *src++) != '\0');
    return address;
}
int main()
{
    char *a = NULL;
    char b[2] = "a";
    myStrcpy(a,b);
    return 0;
}
