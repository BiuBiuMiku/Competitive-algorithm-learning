#include<bits/stdc++.h>
using namespace std;
const long long maxn=6e5+5;
long long n,root;
struct edge{
	long long to,next;
	long long val;
}e[maxn*2];
long long f[maxn];
long long head[maxn],cnt; 
void add(long long x,long long y,long long z){
	e[++cnt].to=y;
	e[cnt].val=z;
	e[cnt].next=head[x];
	head[x]=cnt;
}
bool vis[maxn],vis1[maxn];
long long answer;
void dfs(long long u){
	vis[u]=true;
	for(long long i=head[u];i;i=e[i].next){
		long long v=e[i].to;
		if(vis[v])continue;
		dfs(v);
		f[u]=max(f[u],f[v]+e[i].val);
	}
	
}
void dfs1(long long u){
	vis1[u]=true;
	for(long long i=head[u];i;i=e[i].next){
		long long v=e[i].to;
		if(vis1[v])continue;
		dfs1(v);
		answer=answer+(f[u]-(f[v]+e[i].val));
	}
}
signed main(){
//	freopen("P1131_1.in","r",stdin); 
//	freopen("asd.txt","w",stdout); 
	scanf("%lld%lld",&n,&root);
	for(long long i=1;i<n;i++){
		long long u,v,s;
		scanf("%lld%lld%lld",&u,&v,&s);
		add(u,v,s);add(v,u,s);
	}
	dfs(root);dfs1(root);
//	for(long long i=1;i<=n;i++)printf("%d ",f[i].mmax);
//	printf("\n");
	printf("%lld",answer); 
	return 0;
}
/*
10
1
1 3 3
2 1 1
3 4 2
5 3 1
6 4 5
4 7 1
8 4 2
9 2 4
10 2 9
*/

