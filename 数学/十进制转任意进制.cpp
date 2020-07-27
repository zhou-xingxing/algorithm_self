//十进制转任意进制 
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
	int n,m,p,i;
	char ans[50];
	cin>>m;   //进制 
	cin>>n;   //输入 
	i=0;
	do{                      //预防n=0的情况 
		p=n%m;
		n/=m;
		if(p>=0&&p<=9){
			ans[i]='0'+p;
		}
		//可能超过10进制 
		else{
			ans[i]='A'+p-10;
		}
		i++;
	}while(n);
	for(int k=i-1;k>=0;k--){
		cout<<ans[k];
	}
	return 0;
} 

