/*
	全排列，利用STL库函数next_permutation
	原理和非递归全排列main3类似
 */


#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char a[210] = "abc";
int main(){
	while(scanf("%s",a)!=EOF){
		int len=strlen(a);
		sort(a,a+len);
		cout<<a<<endl;
		while(next_permutation(a,a+len)){
			cout<<a<<endl;
		}
	}
	return 0;
}
