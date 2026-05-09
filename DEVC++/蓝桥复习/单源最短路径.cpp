#include<bits/stdc++.h>
using namespace std;
const int maxm=2e5+5,maxn=1e5+5,oo=2e9; 
int n,m,s;
struct edge{
	int to,val,next;
}E[maxm];
int head[maxn],cnt;
void add(int x,int y,int z){
	E[++cnt].to=y;
	E[cnt].val=z;
	E[cnt].next=head[x];
	head[x]=cnt;
} 
priority_queue< pair<int,int> > q;
int dis[maxn];
bool vis[maxn];
void dij(int st){
	for(int i=1;i<=n;i++)dis[i]=oo,vis[i]=false;
	dis[st]=0;
	q.push(make_pair(0,st));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue; 
		vis[u]=true;
		for(int i=head[u];i;i=E[i].next){
			int v=E[i].to;
			if(dis[u]+E[i].val<dis[v]){
				dis[v]=dis[u]+E[i].val; 
				q.push(make_pair(-dis[v],v));
			}
		}
	} 
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	dij(s);
	for(int i=1;i<=n;i++)printf("%d ",dis[i]);
	return 0;
}

