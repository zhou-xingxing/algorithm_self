#include<stdio.h>
#include<iostream>
using namespace std;

//¿ìËÙÃÝ
#define MOD 1000

int fast_power(int base,int power){
	int ans=1;
	while(power!=0){
		if(power & 1){
			ans=(ans*base)%MOD;
		}
		power=(power>>1);
		base=(base*base)%MOD;
	}
	return ans;
} 

int main(){
	int m,n;
	cin>>m>>n;
	cout<<fast_power(m,n);
	return 0;
}
