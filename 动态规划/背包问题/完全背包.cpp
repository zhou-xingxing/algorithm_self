#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;

// a[j] ����j������Ʒ����ֵ 
int a[10005];

int v[1005];
int w[1005];

int self_max(int a,int b){
	return a>b? a:b;
}

int main(){
	int n,W;
	cin>>n>>W;
	for(int i=0;i<n;i++){
		cin>>w[i]>>v[i];
	}
	for(int i=0;i<n;i++){
		//��01������ȣ���ǰ������������ö�Ӧ"��ȫ" 
		for(int j=w[i];j<=W;j++){
			a[j]=self_max(a[j],v[i]+a[j-w[i]]);
		}
	}
	cout<<a[W];
	return 0;
	
} 

