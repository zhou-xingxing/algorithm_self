#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;



//��֪������ǰ������򣬸����������
void post_order(string pre,string in){
	int len=pre.length();
	if(len==0){
		return;
	}
	if(len==1){
		cout<<pre[0];
		return;
	}
	//������λ�ã�Ҳ�����������ĸ��� 
	int pos=in.find(pre[0]);
	//�ݹ����������
	post_order(pre.substr(1,pos),in.substr(0,pos));
	//�ݹ����������
	post_order(pre.substr(pos+1,len-pos-1),in.substr(pos+1,len-pos-1));
	cout<<pre[0]; 
} 

//��֪��������������򣬸���ǰ�����
void pre_order(string post,string in){
	int len=post.length();
	if(len==0){
		return;
	}
	if(len==1){
		cout<<post[0];
		return;
	}
	
	int pos=in.find(post[len-1]);
	cout<<post[len-1];
	//�ݹ����������
	pre_order(post.substr(0,pos),in.substr(0,pos));
	//�ݹ����������
	pre_order(post.substr(pos,len-pos-1),in.substr(pos+1,len-pos-1));
}

	



int main(){
//	string pre,in;
//	cin>>pre>>in;
//	post_order(pre,in);
	string post,in;
	cin>>post>>in;
	pre_order(post,in);
	return 0; 
}
