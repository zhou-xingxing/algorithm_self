#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

int a[10010];
vector<int> w;
vector<int> v;

int self_max(int a,int b){
	return a>b? a:b;
	
}

//将货物数量按2的不同次幂分开后，转为01背包问题 
int main(){
	int n,W;
	cin>>n>>W;
	for(int i=0;i<n;i++){
		int wi,vi,ci;
		cin>>wi>>vi>>ci;
		int tmp=1;
		while(ci-tmp>0){
			w.push_back(tmp*wi);
			v.push_back(tmp*vi);
			ci-=tmp;
			tmp*=2;
		}
		w.push_back(ci*wi);
		v.push_back(ci*vi);
	}
	for(int i=0;i<w.size();i++){
		for(int j=W;j>=w[i];j--){
			a[j]=self_max(a[j],v[i]+a[j-w[i]]);	
		}
	}
	cout<<a[W];
	return 0;
}
 
