#include <iostream>
#include <cstring>
using namespace std;

int main1(void)
{
	int a[1000];
	for(int i = 0;i<1000;i++){
		a[i] = -1;
	}
	int n;
	cin>>n;
	int x;
	for(int i = 0;i<n;i++){
		cin>>x;
		a[x] = 1;
	}
	for(int i = 0;i<1000;i++){
		if(a[i] == 1)
			cout<< i<<endl;
	}
}

int main(void)
{
	int n;
	int i;
	char str[128] = "0xaaa";
	n = strlen(str);
	int sum = 0;
	int x = 1;
	for(i=n-1;i>1;i--){
		if(str[i] >= '0' && str[i]<='9'){
			sum += (str[i] - '0') * x; 
		}
		else if(str[i]>='a' && str[i]<= 'f'){
			sum += (str[i] - 'a' + 10) * x; 
		}
		x = x*16;
	}
	cout<<sum<<endl;
}
