/*
	全排列递归算法
	1.n个元素的全排列 = （n-1 个元素的全排列）+（另一个元素作为前缀）
	2.出口：如果只有一个元素的全排列，则说明已经排完，则输出数组
	3.不断将每个元素放左第一个元素，然后将这个元素作为前缀，
	  并将其与元素继续全排列，等到出口，出口出去嘚还原数组
	4.解决全排列中有重复情况的方法，将 start 与 i 交换前，
	  检查是否i 与 start～i-1中有重复，有则不交换，没有则交换
*/



#include <iostream>
using namespace std;
int total; /*记录全排列次数*/

void SwapArray(int &a,int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int IsSwap(int* fullArray,int start,int end)
{
	for(int i = start;i<end;i++){
		if(fullArray[i] == fullArray[end])
			return 0;
	}
	return 1;
}
void fullPermutation(int* fullArray,int start,int end,int number)
{
	if(start==end){ /*当只剩一个元素时,输出全排列*/ 
		for(int i = 0;i<number;i++){
			cout<<fullArray[i];
		}
		cout<<endl;
		total++;
	}
	else{ /*不是一个元素，继续将start～end中每个数放到start位置*/
		for(int i=start;i<=end;i++)
			if(IsSwap(fullArray,start,i)){ /*交换前检查 i 是否与 start～i-1 有重复，没有则交换*/ 
				SwapArray(fullArray[start],fullArray[i]);/*将start之后的所有元素依次放到start中*/
				fullPermutation(fullArray,start+1,end,number);/*start位置确定，对start+1～end中的数继续递归*/
				SwapArray(fullArray[start],fullArray[i]);/*换了后要还原*/
			}
		
	}
}



int main(void)
{
	int number; /*全排列长度*/ 
	number= 3;
	int fullArray[3] = {1,2,2};
	fullPermutation(fullArray,0,number-1,number);
	cout<<"Total="<<total;
	return 0;
}
