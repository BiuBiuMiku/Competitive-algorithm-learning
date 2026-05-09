#include<bits/stdc++.h>
using namespace std;
const int maxn=66005;
int n;
int f[maxn];
struct edge{
	int to,next;
}e[maxn];
int cnt,head[maxn];
void add(int x,int y){
	e[++cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
int answer=-1e9;
bool vis[maxn],root[maxn];
void dfs(int u){
	vis[u]=true;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(vis[v])continue;
		dfs(v);
		if(f[v]>0)f[u]+=f[v];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&f[i]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	} 
	dfs(1);
	for(int i=1;i<=n;i++)answer=max(answer,f[i]);
	printf("%d",answer);
	return 0;
}

