#include<bits/stdc++.h>
using namespace std;
int N,M;
const int maxn=1e3+5;
struct edge{
	int to,next;
}E[maxn];
int head[maxn],cnt;
void add(int x,int y){
	E[++cnt].to=y;
	E[cnt].next=head[x];
	head[x]=cnt;
}
bool vis[maxn];
queue<int> q;
int bfs(int s){
	for(int i=1;i<=N;i++)vis[i]=false;
	q.push(s);
	int ans=s;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=head[u];i;i=E[i].next){
			int v=E[i].to;
			q.push(v);
			ans=max(ans,v);
		}
	}
	return ans;
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=N;i++)
		printf("%d ",bfs(i));

	return 0;
}

