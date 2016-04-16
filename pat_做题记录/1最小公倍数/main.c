/*最小公倍数lcm与最大公约数gcd
	二者的关系lcm(a,b) = 	|a*b|/gcd(a,b)
							
*/
#include <stdio.h>
/*最大公约数Greatest Common Divisor*/
int GCD(int a,int b)
{
	if(b)
		while((a%=b)&&(b%=a));
	return a + b;
}
/*最小公倍数Lowest Common Multiple*/
int LCM(int a,int b)
{
	return a * b / GCD(a,b);
}

int main()
{
	int a = 3234;
	int b = 234;
	printf("最小公倍数:%d\n",LCM(a,b));
	printf("最大公约数:%d\n",GCD(a,b));
}