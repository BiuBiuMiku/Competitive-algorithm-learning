#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n; 
struct edge{
	int from,to,next;
}E[maxn<<1];
int head[maxn],cnt;
void add(int x,int y){
	E[++cnt].from=x;
	E[cnt].to=y;
	E[cnt].next=head[x];
	head[x]=cnt;
}
bool vis[maxn],vis1[maxn];
int f[maxn];
int root=1,dep;
void dfs(int u){
	vis[u]=true;
	for(int i=head[u];i;i=E[i].next){
		int v=E[i].to;
		if(vis[v])continue; 
		dfs(v);
		f[u]=max(f[u],f[v]+1);
	}
}
void findroot(int u,int depth){
	vis1[u]=true;
	bool did=false;
	for(int i=head[u];i;i=E[i].next){
		int v=E[i].to;
		if(vis1[v])continue;
		did=true;
		findroot(v,depth+1);
	}
	if(!did && depth>dep)root=u,dep=depth;
} 
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	findroot(1,1);
	dfs(root);
	printf("%d",f[root]);
	return 0;
}

