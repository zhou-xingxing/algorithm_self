//最大公因数的欧几里得算法 
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int gcd(int a,int b){
	if(a==0){
		return b;
	}
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
} 
int main(){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}
