//ͼ����ͨ��--���鼯 

//������Ⱦ
/* 
������������������, ÿ������������һ��Ϊ�������� n�� m, ���� n in (0,30000])��ʾѧ������, 
ÿ��ͬѧ���� 0 �� n-1���б��, min [0,500])��ʾ����¥�ͽ�ѧ¥������. �������� m��, 
ÿһ�б�ʾһ����ѧ¥������¥, ����ÿһ�������� k��ʼ, ��ʾ������¥���ѧ������, ������ k������(�ÿո�ָ�), 
ÿ��������ʾ������ǰ¥���ѧ�����.
����ÿһ������, ���ٶ��� 0 ��ѧ�������Ϊ���Ʋ���.

m,n��Ϊ 0 ʱ�������, ���������ô���. 
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
				second=findfa(second);//����ͬѧ��������һ��ͬѧ���� 
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

