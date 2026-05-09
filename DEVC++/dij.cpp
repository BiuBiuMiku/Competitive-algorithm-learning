#include<bits/stdc++.h>
using namespace std;
//const int MAXM=2e5+5;
//const int oo=1e9+5;
//int n,m,s;
//struct edge{
//	int to,val;
//	int next;
//}e[MAXM];
//int cnt,head[MAXM]; 
//void add(int x,int y,int z){
//	e[++cnt].to=y;
//	e[cnt].val=z;
//	e[cnt].next=head[x];
//	head[x]=cnt;
//}
//bool vis[MAXM];
//int dis[MAXM];
//priority_queue< pair<int,int> >q;
//void dij(int st){
//	for(int i=1;i<=n;i++)dis[i]=oo,vis[i]=false;
//	q.push(make_pair(0,st));
//	dis[st]=0;
//	while(!q.empty()){
//		int u=q.top().second;
//		q.pop();
//		if(vis[u])continue;
//		vis[u]=true;
//		for(int i=head[u];i;i=e[i].next){
//			int v=e[i].to;
//			if(dis[u]+e[i].val<dis[v]){
//				dis[v]=dis[u]+e[i].val;
//				q.push(make_pair(-dis[v],v));
//			}
//		}
//	}
//}
const int MAXN=2e9+5,oo=1e9+5;
int n,m,s;
int dis[MAXN];
bool vis[MAXN];
struct edge{
	int to,val,next;
}e[MAXN];
int head[MAXN],cnt;
void add(int x,int y,int z){
	e[++cnt].to=y;
	e[cnt].val=z;
	e[cnt].next=head[x];
	head[x]=cnt;
}
priority_queue< pair<int,int> >q;
void dij(int st){
	for(int i=1;i<=n;i++)dis[i]=oo,vis[i]=false;
	dis[st]=oo;
	q.push(make_pair(0,st));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].val){
				dis[v]=dis[u]+e[i].val;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);			
			
	}
	dij(s);
	for(int i=1;i<=n;i++)	
		printf("%d ",dis[i]);
	return 0;
}

