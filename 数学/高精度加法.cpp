#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
using namespace std;
//高精度加法 
int main(){
	string a,b;
	int s1[510]={0},s2[510]={0},ans[510]={0};
	cin>>a>>b;
	for(int i=a.size()-1;i>=0;i--){
		s1[a.size()-1-i]=a[i]-'0';
	}
	for(int i=b.size()-1;i>=0;i--){
		s2[b.size()-1-i]=b[i]-'0';
	}
	int jinwei=0;
	int i=0;
	for(;i<a.size()||i<b.size();i++){
		int tmp=s1[i]+s2[i]+jinwei;
		ans[i]=tmp%10;
		jinwei=tmp/10;
	}
	if(jinwei!=0){
		ans[i]=jinwei;
		i++;
	}
	for(int j=i-1;j>=0;j--){
		cout<<ans[j];
	}
	return 0;
	
}

