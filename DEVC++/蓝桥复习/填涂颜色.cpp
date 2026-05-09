#include<bits/stdc++.h>
using namespace std;
const int maxn=35;
int n;
int f[maxn][maxn]; 
const int mx[5]={-1,1,0,0};
const int my[5]={0,0,-1,1};
bool vis[maxn][maxn];
void dfs(int x,int y){
	if(x>n+1 || y>n+1 || x<0 || y<0)return;
	if(f[x][y]==1)return;
	f[x][y]=0;
	for(int i=0;i<4;i++){
		int nx=x+mx[i],ny=y+my[i];
		if(vis[nx][ny])continue;
		vis[nx][ny]=true;
		dfs(nx,ny);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&f[i][j]);
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			if(f[i][j]!=1)f[i][j]=2;
	dfs(0,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",f[i][j]);
		printf("\n");
	}		
	return 0;
}

