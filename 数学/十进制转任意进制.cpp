//ʮ����ת������� 
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
	int n,m,p,i;
	char ans[50];
	cin>>m;   //���� 
	cin>>n;   //���� 
	i=0;
	do{                      //Ԥ��n=0����� 
		p=n%m;
		n/=m;
		if(p>=0&&p<=9){
			ans[i]='0'+p;
		}
		//���ܳ���10���� 
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

