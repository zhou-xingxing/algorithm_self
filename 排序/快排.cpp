#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;

void swap(int a[],int left,int right){
	int tmp=a[left];
	a[left]=a[right];
	a[right]=tmp;
}

//快排+3数取中 
void quick_sort(int a[],int left,int right){
	
	if(right<=left){
		return;
	}
	
	int mid=left+(right-left)/2;
	if(a[left]>a[right]){
		swap(a,left,right);
	}
	if(a[mid]>a[right]){
		swap(a,mid,right);
	}
	if(a[mid]>a[left]){
		swap(a,mid,left);
	}
	
	int flag=a[left];
	int i=left,j=right;
	while(i<j){
		while(i<j&&a[j]>flag)
			j--;
		a[i]=a[j];
		while(i<j&&a[i]<=flag)
			i++;
		a[j]=a[i];
	}
	a[i]=flag;
	quick_sort(a,left,i-1);
	quick_sort(a,i+1,right);
} 

//求第k小的数
int quick_sort_k(int a[],int left,int right,int target){
	
	if(right<left){
		return -1;
	}
		
	int flag=a[left];
	int i=left,j=right;
	while(i<j){
		while(i<j&&a[j]>flag)
			j--;
		a[i]=a[j];
		while(i<j&&a[i]<=flag)
			i++;
		a[j]=a[i];
	}
	a[i]=flag;
	if(i==target-1){
		return a[i];
	}
	if(i<target-1){
		return quick_sort_k(a,i+1,right,target);
	}
	if(i>target-1){
		return quick_sort_k(a,left,i-1,target);
	}
		
}  

int main(){
	int n,m,k;
	int a[200010];
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&a[m+i]);
	}
	int ans=quick_sort_k(a,0,m+n-1,k);
	
	printf("%d",ans);
	return 0;
}
 
