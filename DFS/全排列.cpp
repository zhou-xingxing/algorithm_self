#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;

//»ØËÝ 
int flag[10];

int track[10];
void dfs(int n,int num){
	if(num==n){
		for(int i=0;i<n;i++){
			printf("%d ",track[i]);
			
		}
		printf("\n");
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			if(flag[i]==0){
				flag[i]=1;
				track[num]=i;
				dfs(n,num+1);
				flag[i]=0;
			}
		}
	}
} 

int main(){
	int n;
	scanf("%d",&n);
	dfs(n,0);
	return 0;
}

