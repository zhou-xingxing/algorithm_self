#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int val;
	struct node * next;
	node(int x){
		val=x;
		next=NULL;
	}
}; 

//���� 
node * create(int num){
	node * head=new node(0); //��һ��ͷ���
	node * p1=head;
	while(num--){
		int tmp;
		cin>>tmp;
		p1->next=new node(tmp);
		p1=p1->next;	
	} 
	//���ز���ͷ�������� 
	return head->next;
	
}

//��������ϲ� 
node * merge(node * l,node * r){
	if(!l){
		return r;
	}
	if(!r){
		return l;
	}
	node * head=new node(0);
	node * cur=head;
	while(l&&r){
		if(l->val<r->val){
			cur->next=l;
			l=l->next;
			cur=cur->next;
		}
		else{
			cur->next=r;
			r=r->next;
			cur=cur->next;
		}
	}
	if(l){
		cur->next=l;
	}
	if(r){
		cur->next=r;
	}
	return head->next;
	
} 

node * mergesort(node * head){
	//���û�нڵ��ֻ��һ���ڵ㣬ֱ�ӷ��� 
	if(!head||!head->next){
		return head;
	}
	
	node * p1, * p2, * cur;
	cur=p1=p2=head;
	//Ѱ�������е� 
	while(p2&&p2->next){
		cur=p1;
		p1=p1->next;
		p2=p2->next->next;		
	} 
	//��ǰ�벿�ּӸ�β�� 
	cur->next=NULL;

	
	return merge(mergesort(head),mergesort(p1));
		
}

int main(){
	int n;
	cin>>n;
	node * head;
	head=create(n);
	head=mergesort(head);
	while(head){
		cout<<head->val<<' ';
		head=head->next;
	}
	return 0;
}
