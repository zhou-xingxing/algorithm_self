#include<iostream>
using namespace std;

/*

����һ������n+1������������nums�������ֶ���1-n֮�䣨����1��n��������ֻ��һ���ظ����������ҳ�����ظ����� 


���ֶ���1-n֮�䣬��ֻ��1�����ֻ��ظ����֣��������1-n����������Ԫ�ؽ������
ֻ����һ�εĶ��ᱻ����0�����Ľ�����Ƕ�����Ǹ����� 

�÷�������Ҫ����ռ䣬������������󼴿ɵó����  

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
