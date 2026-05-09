#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int maxm=2e5+5;
const int oo=1e9+5;
int n,m,s;
struct edge{
	int to,next,val;
}e[maxm];
int cnt,head[maxn];
void add(int x,int y,int z){
	e[++cnt].to=y;
	e[cnt].val=z;
	e[cnt].next=head[x];
	head[x]=cnt;
}
priority_queue< pair<int,int> >q;
int dis[maxn];
bool vis[maxn];
void dij(int st){
	for(int i=1;i<=n;i++)
		vis[i]=false,dis[i]=oo;
	q.push(make_pair(0,st));
	dis[st]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(dis[u]+e[i].val<dis[v]){
				dis[v]=dis[u]+e[i].val;
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

