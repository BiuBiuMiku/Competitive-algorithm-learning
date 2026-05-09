#include<bits/stdc++.h>
using namespace std;
int n;
const int wx[5]={0,0,1,-1};
const int wy[5]={1,-1,0,0};
int map1[35][35]; 
void ou(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",map1[i][j]);
		printf("\n");
	}
}
bool vis[35][35];
queue< pair<int,int> >q;
void bfs(){
	q.push(make_pair(0,0));
	vis[0][0]=true;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nx=x+wx[i],ny=y+wy[i];
			if(nx<0||nx>n+1||ny<0||ny>n+1)continue;
			if(!vis[nx][ny]&&map1[nx][ny]!=1){
				q.push(make_pair(nx,ny));
				vis[nx][ny]=true;
				map1[nx][ny]=0;
			} 
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
	bfs();
	ou();
	return 0;
}

