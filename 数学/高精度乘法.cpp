#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;
//高精度乘法 
int main(){
	string a,b;
	int s1[510]={0},s2[510]={0},ans[1010]={0};
	int a_length,b_length;
	cin>>a>>b;
	int fa=0,fb=0;//是否有负号 
	for(int i=a.size()-1;i>=1;i--){
		s1[a.size()-1-i]=a[i]-'0';
	}
	if(a[0]=='-'){
		fa=1;
		a_length=a.size()-1;
	} 
	else{
		s1[a.size()-1]=a[0]-'0';
		a_length=a.size();
	}
	
	for(int i=b.size()-1;i>=0;i--){
		s2[b.size()-1-i]=b[i]-'0';
	}
	
	if(b[0]=='-'){
		fb=1;
		b_length=b.size()-1;
	} 
	else{
		s2[b.size()-1]=b[0]-'0';
		b_length=b.size(); 
	}
	
	
	for(int i=0;i<a_length;i++){
		int jinwei=0;
		for(int j=0;j<b_length;j++){
			ans[i+j]=s1[i]*s2[j]+jinwei+ans[i+j];
			jinwei=ans[i+j]/10;
			ans[i+j]=ans[i+j]%10;
		}
		ans[i+b_length]=jinwei;
	}
	
	int ans_length=a_length+b_length;
	//去除高位的0，同时考虑只有0的情况 
	while(ans[ans_length-1]==0&&ans_length>1){
		ans_length--;
	}
	
	if(fa!=fb&&ans[0]!=0){
		cout<<'-';
	}
	for(int j=ans_length-1;j>=0;j--){
		cout<<ans[j];
	}
	return 0;
	
}

