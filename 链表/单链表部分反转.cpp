#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node * next;
	node(int num){
		data=num;
		next=NULL;
	}
};

int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b); 

	//加头结点，方便统一操作 
	node * head=new node(0);
	node * p1,*p2;
	p1=head;
	//建表 
	while(n--){
		int tmp;
		scanf("%d",&tmp);
	
		p1->next=new node(tmp);
		p1=p1->next;	
	}
	int count=1;
	p1=head;
	p2=head->next; 
	node * pa, *paa;
	paa=NULL;
	while(count<=a){
		p2=p2->next;
		p1=p1->next;
		if(paa==NULL){
			paa=head;
		}
		else{
			paa=paa->next;	
		}
		count++;
	}
	pa=p1;//此时pa指向a，paa指向a前一个 
	
//	cout<<p1->data<<endl;
//	cout<<p2->data<<endl;
//	cout<<pa->data<<endl;
//	cout<<paa->data<<endl;
	
	 
	while(count<=b){
		node * tmp=p2->next;
		p2->next=p1;
		p1=p2;
		p2=tmp;
		count++;
	}
	//此时p2指向b后一个，p1指向b 
	//原a前的结点指向b，原a结点指向b后一个结点 
	paa->next=p1; 
	pa->next=p2;	
	p1=head->next; 
	while(p1){
		printf("%d ",p1->data);
	
		p1=p1->next;
	}
	
	
	return 0;
	
}

