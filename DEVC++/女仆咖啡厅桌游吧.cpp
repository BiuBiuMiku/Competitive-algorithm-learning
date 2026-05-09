#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;
int head[maxn],cnt;
struct edge{
	int to,next;
}e[maxn*2];
int f[maxn]; 
int leaf[maxn];
void add(int x,int y){
	e[++cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
bool vis[maxn];
bool dfs(int u){
	vis[u]=true;
	bool tag=true;
	int le=0;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(vis[v])continue;
		tag=false;
		if(dfs(v))le++;
		else f[u]+=f[v];
	}
	if(tag)return true;
	f[u]+=(le+1)/2;
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	} 
	dfs(1);
	printf("%d",f[1]);
	return 0;
}

