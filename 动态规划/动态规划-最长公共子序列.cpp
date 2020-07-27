//动态规划-最长公共子序列 
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;
int ss[105][105];
char a[105];
char b[105];
int mmax(int a,int b){
	return a>b?a:b;
}
int main(){
	cin>>a>>b;
	int numa=strlen(a);
	int numb=strlen(b);
	memset(ss,0,sizeof(ss));
	for(int i=0;i<=numa;i++){
		ss[i][0]=0;
	}
	for(int i=0;i<=numb;i++){
		ss[0][i]=0;
	}
	for(int i=1;i<=numa;i++){
		for(int j=1;j<=numb;j++){
			if(a[i-1]==b[j-1]){                //注意下标 
				ss[i][j]=ss[i-1][j-1]+1;          //小心数组越界下标为负 
			}
			else{
				ss[i][j]=mmax(ss[i-1][j],ss[i][j-1]);
			} 
		}
	}
	cout<<ss[numa][numb];
	return 0;
} 

