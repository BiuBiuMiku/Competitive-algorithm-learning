#include<bits/stdc++.h>
using namespace std;
int map1[35][35];
int n;
const int wx[5]={0,0,1,-1};
const int wy[5]={1,-1,0,0}; 
void ou(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",map1[i][j]);
		printf("\n");
	}
}
void dfs(int x,int y){
//	ou();printf("\n");
//	if(x>n || x<0 || y>n || y<0)return;
	for(int i=0;i<4;i++){
		int nx=x+wx[i],ny=y+wy[i];
		if(nx>n+1||nx<0||ny>n+1||ny<0)continue;
		if(map1[nx][ny]==2){
			map1[nx][ny]=0;
			dfs(nx,ny);	
	//		printf("do");
		}
	}
}
int main(){
	scanf("%d",&n); 	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&map1[i][j]);
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			if(map1[i][j]!=1)map1[i][j]=2;		
	dfs(0,0);
	ou();
	return 0;
}

