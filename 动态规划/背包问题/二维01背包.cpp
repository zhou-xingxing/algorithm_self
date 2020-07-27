#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int a[1005][1005];

int w[1005];
int c[1005];
int v[1005];
//有两个限制条件，本质与01背包相同 

int self_max(int a,int b){
	return a>b? a:b;
}

int main(){
	int n,W,C;
	cin>>n>>W>>C;
	for(int i=0;i<n;i++){
		cin>>w[i]>>c[i]>>v[i];
	}

	for(int i=0;i<n;i++){
		for(int j=W;j>=w[i];j--){
			for(int k=C;k>=c[i];k--){			
				a[j][k]=self_max(a[j][k],v[i]+a[j-w[i]][k-c[i]]);
				
			}
		}
	}
	cout<<a[W][C];
	return 0;
}
