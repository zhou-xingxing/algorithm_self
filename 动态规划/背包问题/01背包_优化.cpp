#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int a[100010];
vector<int> wi;
vector<int> vi;
vector<int> ans;
int self_max(int a,int b){
	return a>b? a:b;
}

int main(){
	int time;
	cin>>time;
	for(int k=0;k<time;k++){
		wi.clear();
		vi.clear();
		int n,W;
		int w,v;
		cin>>n>>W;
		for(int i=0;i<=W;i++){
			a[i]=0;
		}
		for(int i=0;i<n;i++){
			cin>>w>>v;
			wi.push_back(w);
			vi.push_back(v);
		}
		for(int i=0;i<n;i++){
			//从后往前遍历，优化空间 
			for(int j=W;j>=wi[i];j--){
				a[j]=self_max(a[j],vi[i]+a[j-wi[i]]);
			}
		}
		ans.push_back(a[W]);
		
	}
	for(int i=0;i<ans.size()-1;i++){
		cout<<ans[i]<<endl;
	}
	cout<<ans[ans.size()-1];
	return 0;
}

