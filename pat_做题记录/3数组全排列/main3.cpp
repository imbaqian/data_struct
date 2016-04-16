/*
   全排列的非递归算法
   1.从后向前找第一双相邻的递增数字ab，称前一个数字a为替换数，其下标为替换点
   2.然后从替换数后面找一个比替换数大的最小数c，然后交换 a，c 
   然后再将替换点后的字符串逆序Reverse
   3.如果达到这个数组的最大排列4321，则结束整个循环
   4.函数最初输入数组的最小排列1234
 */
#include <cstring>
#include <iostream>
using namespace std;

char* FindMaxForOne(char *Replace,char *pEnd)
{	
	char *FirstMoreThanReplcae = pEnd;/* 第一个大于Replace的数	*/
	while(*FirstMoreThanReplcae <= *Replace)
		FirstMoreThanReplcae--;
	return FirstMoreThanReplcae;
}

void Swap(char* a,char*b)
{
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void Reverse(char* begin,char *end)
{
	while (begin < end)
		Swap(begin++,end--);
	
}
void Print(char *s)
{
	cout<<s<<endl;
}
void Perm( char *s)
{
	char *pEnd = s + strlen(s) - 1;
	char *Replace = pEnd;/*替换点*/
	char *RepNext ;/*替换点的下一个数*/
	char *pMax;/*地换点后比替换点大的最小数*/
	Print(s); /*输出原数组*/
	while(Replace != s){
		RepNext = Replace;
		Replace--;
		if(*Replace < *RepNext){ /*找到一对递增序列ab*/
			pMax = FindMaxForOne(Replace,pEnd);/*找与替换点交换的点*/
			Swap(Replace,pMax);
			Reverse(RepNext,pEnd);
			Print(s);
			Replace = pEnd;
		}
	}

}
int main(void)
{
	char a[] = "122";
	Perm(a);
	return 0;
}
