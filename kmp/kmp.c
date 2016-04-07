#include <stdio.h>
#include <string.h>
#include <malloc.h>

#if 1
void GetNext(char pattent[],int next[])
{
	int j,k;
	int len;
	next[0] = 0;
	len = strlen(pattent);
	for(j = 1; j<len; j++){
		k = next[j-1];
		/*不断递归判断是否存在子对称，k=0说明不再有子对称
		  pattent[i] != pattent[k]说明虽然对称，但是对称
		  后面的值和当前的字符值不向等，所以继续递推
		 */
		while(pattent[j] != pattent[k] && k!=0 )
			k = next[k-1];
		if(pattent[j] == pattent[k])/*找到了这个子对称，或者直接继承了前面的对称性，*/
			next[j] = k+1;
		else/*如果遍历了所有子对称都无香，说明这个新字符不具有对称性w*/
			next[j] = 0;
	}
}

void KMP(char target[],char pattent[])
{
	int i = 0;
	int j = 0;
	int next[20];
	GetNext(pattent,next);
	while(target[i] != '\0' && pattent[j] != '\0'){
		if( target[i] == pattent[j] )
		{
			i++;
			j++;
		}
		else
		{
			j = next[j-1];	
			if(j == 0)
				i++;
		}
	}
	if(j == strlen(pattent))
		printf("%d\n",i-j);
	else
		printf("没有");
}

#endif
/*-------上面自己写的乱七八糟，下面参考大神们的把-------------------------------*/
/*next[j] = k 表示当str[i] != ts[j]时,j指针的下一个位置*/

			
int main()
{
	char A[] = "BBC ABCDAB ABCDABCDABDE";
	char B[] = "DAB";
	KMP(A,B);
}
