//����ɸ�� 
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int prim[10005];    //�����Ѿ����ֵ����� 
bool isprim[10005]; 
int primnum;     //ͳ�������ĸ���
 
//��10000�ڵ����� 
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
