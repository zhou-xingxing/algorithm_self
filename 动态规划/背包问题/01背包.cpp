#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;

// a[i][j] 重量j以下，前i个物品最大价值 
int a[105][10005];

int v[105];
int w[105];

int main(){
	int n,W;
	cin>>n>>W;
	for(int i=0;i<n;i++){
		cin>>w[i]>>v[i];
		
	}	
	for(int i=0;i<=W;i++){
		if(i>=w[0]){
			a[0][i]=v[0];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<=W;j++){
			a[i][j]=a[i-1][j];
			if(j>=w[i]){
				if(a[i][j]<(a[i-1][j-w[i]]+v[i])){
					a[i][j]=(a[i-1][j-w[i]]+v[i]);
				}
			}
		}
	}
	cout<<a[n-1][W];
	return 0;
} 

