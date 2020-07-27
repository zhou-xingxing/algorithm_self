#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
//克鲁斯卡尔算法


//并查集-检验连通性 
int father[200100];

int get_father(int k){		
	if(father[k]==k){
		return k;
	}
	else{
		father[k]=get_father(father[k]);
		return father[k];
	}
}

struct line{
	int a,b;
	int weight;
	
	bool operator<(line & p){
		return weight<p.weight;
	}
};

//stack空间有限 2M 524288个int 
line l[500100];

int main(){
	int n,m;
	long long ans=0;
	int num=0;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
	for(int i=0;i<m;i++){
		line tmp;
		cin>>tmp.a>>tmp.b>>tmp.weight;
		l[i]=tmp;
	}
	sort(l,l+m);
	for(int i=0;i<m;i++){
		int fa=get_father(l[i].a);
		int fb=get_father(l[i].b);
		
		if(fa!=fb){
			num++;
			ans+=l[i].weight;
			father[fa]=fb;
			
		} 
		if(num==n-1){
			break;
		}
		
	}
	cout<<ans;
	
	return 0;
}

