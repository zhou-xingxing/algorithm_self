#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;

//查找比给定整数 p小的，下标最大元素。找到则返回其下标，否则返回-1
int low_bound(int a[],int length,int p){
	int l=0;
	int r=length-1;
	int pos=-1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(a[mid]>=p){
			r=mid-1;
		}
		else{
			pos=mid;
			l=mid+1;
		}
	}
	return pos;
} 

int high_bound(int a[],int length,int p){
	int l=0;
	int r=length-1;
	int pos=length;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(a[mid]<=p){
			l=mid+1;
		}
		else{
			pos=mid;
			r=mid-1;
		}
	}
	return pos;
} 

int main(){
	int n,target;
	cin>>n;
	int * a=new int [n+1];
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>target;
	int l_bound=low_bound(a,n,target);
	int r_bound=high_bound(a,n,target);
	cout<<r_bound-l_bound-1;
	
	delete [] a;
	return 0;
	
}





