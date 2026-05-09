#include<bits/stdc++.h>
using namespace std;
const int maxn=6e3+5;
int n;
int f[maxn][2];
struct edge{
	int to,next;
}e[maxn];
int cnt,head[maxn];
bool root[maxn];
void add(int x,int y){
	e[++cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
bool vis[maxn];
void dfs(int u){
	if(vis[u])return;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		dfs(v);
		vis[v]=true;
		f[u][1]+=f[v][0];
		f[u][0]+=max(f[v][1],f[v][0]);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&f[i][1]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(v,u);
		root[u]=true;
	}
	for(int i=1;i<=n;i++){
		if(!root[i]){
			dfs(i);
			printf("%d",max(f[i][1],f[i][0]));
			break;
		}
	}
	return 0;
}

