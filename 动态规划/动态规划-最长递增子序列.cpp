//最长递增子序列 
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[105];
int sequence[105];
int mmax(int a,int b){
	return a>b?a:b;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>sequence[i];
		dp[i]=1;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(sequence[i]>=sequence[j]){
				dp[i]=mmax(dp[i],dp[j]+1);
			}
		}
	}
	int ans=1;
	for(int i=0;i<n;i++){
		ans=mmax(dp[i],ans);
	}
	cout<<ans;
	return 0;
	
} 

