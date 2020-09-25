#include<iostream>
using namespace std;

/*

给定一个包含n+1个整数的数组nums，其数字都在1-n之间（包括1和n），假设只有一个重复的整数，找出这个重复的数 


数字都在1-n之间，且只有1个数字会重复出现，则可以用1-n依次与数组元素进行异或
只出现一次的都会被异或成0，最后的结果就是多余的那个数字 

该方法不需要额外空间，且数组输入完后即可得出结果  

*/

int main(){
	int n,tmp;
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tmp;
		ans=i^tmp^ans;
	}
	cin>>tmp;
	ans=ans^tmp;
	cout<<ans;
	return 0;
} 
