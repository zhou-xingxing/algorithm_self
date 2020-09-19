//图的连通性--并查集 

//疾病传染
/* 
输入包含多个测试用例, 每个测试用例第一行为两个整数 n和 m, 其中 n in (0,30000])表示学生总数, 
每个同学按从 0 到 n-1进行编号, min [0,500])表示宿舍楼和教学楼的总数. 接下来是 m行, 
每一行表示一个教学楼或宿舍楼, 并且每一行以整数 k开始, 表示到过该楼里的学生人数, 紧接着 k个整数(用空格分隔), 
每个整数表示到过当前楼里的学生编号.
对于每一组输入, 都假定第 0 号学生被诊断为疑似病例.

m,n均为 0 时输入结束, 该用例不用处理. 
*/
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int  father[30010];

int findfa(int n){
	if(father[n]==n){
		return n;
	}
	else{
		int tmp=findfa(father[n]);
		father[n]=tmp;
		return tmp;
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	while(n||m){
		for(int i=0;i<n;i++){
			father[i]=i;
		}
		for(int i=0;i<m;i++){
			int num;
			cin>>num;
			int first;
			cin>>first;
			first=findfa(first);
			for(int j=1;j<num;j++){
				int second;
				cin>>second;
				second=findfa(second);//后面同学都连到第一个同学那里 
				father[second]=first;
			}
		}
		int sickfather=findfa(0);
		int sum=0;
		for(int i=0;i<n;i++){
			int fa=findfa(i);
			if(fa==sickfather){
				sum++;
			}
		}
		cout<<sum<<endl;
		cin>>n>>m;
	}
	return 0;
}

