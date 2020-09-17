#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int height[105][105];
int snow[105][105];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int row,col;



int dfs(int x,int y){
	if(snow[x][y]>0){
		return snow[x][y];
	}
	int tmp=0;
	for(int i=0;i<4;i++){
		int newx=x+dir[i][0];
		int newy=y+dir[i][1];
		if(newx>=0&&newx<row&&newy>=0&&newy<col&&height[newx][newy]<height[x][y]){
			tmp=max(tmp,dfs(newx,newy));
		}
	}
	tmp+=1;
	snow[x][y]=tmp;
	return tmp;
} 


int main(){
	cin>>row>>col;
	int ans=0;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>height[i][j];
		}
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			ans=max(ans,dfs(i,j));
		}
	}
	cout<<ans;
	return 0;
	
}
