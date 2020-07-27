//素数筛法 
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int prim[10005];    //储存已经发现的素数 
bool isprim[10005]; 
int primnum;     //统计素数的个数
 
//找10000内的素数 
void find(){
	for(int i=1;i<10001;i++){
		isprim[i]=true;
	}
	for(int i=2;i<10001;i++){
		if(isprim[i]==false){
			continue;
		}
		else{
			prim[primnum]=i;
			primnum++;	
		}
		for(int j=i*i;j<10001;j+=i){
			isprim[j]=false;
		}
	}
} 

int main(){
	int n;
	cin>>n;
	find();
	for(int i=0;prim[i]<=n&&i<primnum;i++){
		cout<<prim[i]<<' ';
	}
	return 0;
}
