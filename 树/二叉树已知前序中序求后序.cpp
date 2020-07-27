#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;



//已知二叉树前序和中序，给出后序遍历
void post_order(string pre,string in){
	int len=pre.length();
	if(len==0){
		return;
	}
	if(len==1){
		cout<<pre[0];
		return;
	}
	//根结点的位置，也是左子树结点的个数 
	int pos=in.find(pre[0]);
	//递归遍历左子树
	post_order(pre.substr(1,pos),in.substr(0,pos));
	//递归遍历右子树
	post_order(pre.substr(pos+1,len-pos-1),in.substr(pos+1,len-pos-1));
	cout<<pre[0]; 
} 

//已知二叉树后序和中序，给出前序遍历
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
	//递归遍历左子树
	pre_order(post.substr(0,pos),in.substr(0,pos));
	//递归遍历右子树
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
